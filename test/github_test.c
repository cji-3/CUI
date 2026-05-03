#include "../include/CUI.h"
#include "../extern/SDL/include/SDL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   //內容測試放置區域
    CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);
    if (CUI_GetWindowWidth()!=640 || CUI_GetWindowHeight()!=360) {
        printf("窗口尺寸不正確！\n");
        return 1; 
    }
     SDL_Renderer* renderer = CUI_GetRenderer();
    if (renderer == NULL) {
        printf("無法取得 renderer！\n");
        CUI_Quit();
        return -1;
    }
    printf("窗口尺寸正確！\n");
    return 0; 
}