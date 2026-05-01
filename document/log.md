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