cmake_minimum_required(VERSION 3.10)
project(CUI C)

# 設定 C 語言標準
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. 全域編譯參數
# -DSDL_MAIN_HANDLED: 避免 SDL 接管 main 進入點
add_compile_options(-Wall -O0 -DSDL_MAIN_HANDLED)

# 2. 設定外部庫路徑 (對應 extern/SDL)
set(SDL_EXT_DIR "${CMAKE_SOURCE_DIR}/extern/SDL")
set(SDL_INCLUDE_DIR "${SDL_EXT_DIR}/include")
set(SDL_LIB_DIR "${SDL_EXT_DIR}/lib")


# 包含標頭檔搜尋路徑 (include 目錄與 SDL 標頭檔)
include_directories(include)
include_directories("${SDL_INCLUDE_DIR}")

# 3. 定義 SDL2 連結依賴 (MinGW 必要系統庫)
set(SDL2_STATIC_DEPS
    "${SDL_LIB_DIR}/libSDL2.a"
    mingw32
    winmm
    imm32
    version
    gdi32
    setupapi
    ole32
    oleaut32
    uuid
    shell32
    advapi32
)

# 4. 自動搜刮 src 底下的原始碼
aux_source_directory(src DIR_SRCS)
message(STATUS "找到的 CUI 原始碼: ${DIR_SRCS}")

# --- 建立靜態庫 (libCUI.a) ---
add_library(cui_static STATIC ${DIR_SRCS})
set_target_properties(cui_static PROPERTIES
    OUTPUT_NAME "CUI"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/static"
)

# --- 建立動態庫 (libCUI.dll) ---
add_library(cui_shared SHARED ${DIR_SRCS})
set_target_properties(cui_shared PROPERTIES
    OUTPUT_NAME "CUI"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/shared"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/shared"
)
# 當編譯動態庫時加入 CUI_EXPORTS 宏
target_compile_definitions(cui_shared PRIVATE CUI_EXPORTS)
target_link_libraries(cui_shared PRIVATE ${SDL2_STATIC_DEPS})

# --- 建置測試程式 ---
# 來源已修正為 test/test.c
add_executable(main_test test/test.c)

# 連結順序：測試程式 -> CUI 靜態庫 -> SDL2 核心
target_link_libraries(main_test PRIVATE
    cui_static
    ${SDL2_STATIC_DEPS}
)

# 5. 針對 MinGW 環境的連結優化
if(MINGW)
    # -mconsole: 確保執行時會跳出 CMD 視窗顯示 printf 內容
    # -static: 強制靜態連結標準庫，避免遺失 DLL 報錯
    target_link_options(main_test PRIVATE "-mconsole" "-static")
    target_link_options(cui_shared PRIVATE "-static-libgcc")
endif()