# 最低 CMake 版本與專案資訊
cmake_minimum_required(VERSION 3.10)
project(CUI VERSION 1.0.0 LANGUAGES C)

# 使用 C99 顯式啟用標準 C，並關閉編譯器擴展
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 依據平台開啟對應的警告等級
if(MSVC)
    add_compile_options(/W4 /permissive- /utf-8)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wdouble-promotion -Wformat=2 -Wcast-align)
endif()

# 專案路徑變數
set(CUI_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(CUI_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(EXTERN_DIR ${PROJECT_SOURCE_DIR}/extern)

# 自動掃描 extern/ 目錄下所有的外部庫
# 為每個 extern/*/include 新增到全域 include path
file(GLOB EXTERN_SUBDIRS "${EXTERN_DIR}/*")
foreach(SUBDIR ${EXTERN_SUBDIRS})
    if(IS_DIRECTORY ${SUBDIR})
        # 檢查該子目錄是否有 include 資料夾
        if(IS_DIRECTORY "${SUBDIR}/include")
            list(APPEND EXTERNAL_INCLUDE_DIRS "${SUBDIR}/include")
            message(STATUS "Found external include: ${SUBDIR}/include")
        endif()

        # 檢查該子目錄是否有 lib 資料夾，若有則搜尋庫檔
        if(IS_DIRECTORY "${SUBDIR}/lib")
            # 取得目錄名稱作為庫名稱（例如 SDL2, CLS）
            get_filename_component(LIB_NAME ${SUBDIR} NAME)

            # 嘗試在該目錄找到庫檔
            file(GLOB LIB_FILES "${SUBDIR}/lib/*.a" "${SUBDIR}/lib/*.dll.a" "${SUBDIR}/lib/*.so" "${SUBDIR}/lib/*.dylib")
            if(LIB_FILES)
                # 使用第一個找到的庫檔
                list(GET LIB_FILES 0 LIB_FILE)
                set(${LIB_NAME}_LIBRARY ${LIB_FILE})
                message(STATUS "Found external library (${LIB_NAME}): ${LIB_FILE}")
                list(APPEND EXTERNAL_LIBRARIES ${LIB_FILE})
            else()
                message(STATUS "No library files found in ${SUBDIR}/lib")
            endif()
        endif()
    endif()
endforeach()

# 檢查是否至少找到了必要的庫（例如 SDL2）
if(NOT EXTERNAL_LIBRARIES)
    message(FATAL_ERROR "No external libraries found in ${EXTERN_DIR}")
endif()

message(STATUS "External include directories: ${EXTERNAL_INCLUDE_DIRS}")
message(STATUS "External libraries: ${EXTERNAL_LIBRARIES}")

# CUI 的原始碼檔案清單（自動掃描 src/ 下所有 .c 檔案）
file(GLOB CUI_SOURCES "${CUI_SOURCE_DIR}/*.c")
message(STATUS "Found source files: ${CUI_SOURCES}")

# 建立靜態與動態版本的 CUI 函式庫
add_library(CUI_static STATIC ${CUI_SOURCES})
add_library(CUI_shared SHARED ${CUI_SOURCES})

# 設定 CUI 函式庫的 include path（包含自己的 include 與所有外部 include）
target_include_directories(CUI_static PUBLIC
    ${CUI_INCLUDE_DIR}
    ${EXTERNAL_INCLUDE_DIRS}
)

target_include_directories(CUI_shared PUBLIC
    ${CUI_INCLUDE_DIR}
    ${EXTERNAL_INCLUDE_DIRS}
)

# 連結所有外部庫
target_link_libraries(CUI_static PUBLIC ${EXTERNAL_LIBRARIES})
target_link_libraries(CUI_shared PUBLIC ${EXTERNAL_LIBRARIES})

# 設定輸出資料夾位置
# 靜態庫 (.a) 與匯入庫 (.dll.a) 放到 bin/
# 動態庫 (.dll) 放到 lib/
set_target_properties(CUI_static PROPERTIES
    OUTPUT_NAME CUI
    PREFIX lib
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

set_target_properties(CUI_shared PROPERTIES
    OUTPUT_NAME CUI
    PREFIX lib
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)

# 將所有測試可執行檔輸出到 test/ 目錄
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test)

# main_test 目標
add_executable(main_test test/test.c)
target_include_directories(main_test PRIVATE ${CUI_INCLUDE_DIR})
target_link_libraries(main_test PRIVATE CUI_shared)
# 建構後將 lib/ 內容複製到 test 目錄
add_custom_command(TARGET main_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/lib
        ${PROJECT_SOURCE_DIR}/test
)

# github_test 目標（如果存在的話）
if(EXISTS "${PROJECT_SOURCE_DIR}/test/github_test.c")
    add_executable(github_test test/github_test.c)
    target_include_directories(github_test PRIVATE ${CUI_INCLUDE_DIR})
    target_link_libraries(github_test PRIVATE CUI_shared)
    add_custom_command(TARGET github_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/bin
            ${PROJECT_SOURCE_DIR}/test
    )
    add_custom_command(TARGET github_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/lib
            ${PROJECT_SOURCE_DIR}/test
    )
endif()
