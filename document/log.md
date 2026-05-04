# CUI：

## C語言UI函式庫 基於SDL

## 2026/04/29

環境建置完成
使用CMake建置

對SDL的連結使用靜態庫 使編譯後的成品不會有SDL的.a或.dll

資料夾結構：
- include 放標頭檔(內另有SDL資料夾放SDL的標頭檔)
- lib 放編譯後的檔案(內另有shared資料夾放動態庫(.dll)和static資料夾放靜態庫(.a))
- SDL_lib 放SDL靜態靜態庫(.a)
- src 放實現檔
- test 放測試(範例)程式碼
- build 放CMake快取檔案

//此區需修改
CUI/
├── build/              # CMake 快取與編譯暫存檔
├── extern/             # 外部相依庫 (如 SDL 原始檔案)
├── include/            # 公用標頭檔 (.h)
│   ├── SDL/            # SDL 的標頭檔
│   ├── CUI.h           # 總門面標頭檔
│   └── CUI_init.h
├── lib/                # 編譯後的庫檔案
│   ├── shared/         # 動態庫 (.dll)
│   └── static/         # 靜態庫 (.a)
├── SDL_lib/            # SDL 專用的靜態庫 (.a)
├── src/                # 原始碼實現檔 (.c)  │   └── CUI.c           # 核心實現
├── test/               # 測試與範例程式碼
│   └── test.c          # 測試進入點
├── CMakeLists.txt      # 建置設定檔
└── run_build.bat       # 自動化編譯與執行腳本