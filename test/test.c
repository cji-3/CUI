#include<stdbool.h>
#include<windows.h>

#include "../include/CUI.h"
#include<stdio.h>

int main(int argc,char* argv[]) {
	if (CUI_Init("CUI 測試視窗", 
                 CUI_INIT_WINDOW_POS_CENTERED,
                 CUI_INIT_WINDOW_POS_CENTERED,
                 800, 600, 
                 CUI_INIT_WINDOW_MODE_SHOWN) != 0) {
        printf("初始化失敗！\n");
        return -1;
    }

    printf("視窗建立成功！寬=%d, 高=%d\n", 
           CUI_GetWindowWidth(), CUI_GetWindowHeight());

    SDL_Renderer* renderer = CUI_GetRenderer();
    if (renderer == NULL) {
        printf("無法取得 renderer！\n");
        CUI_Quit();
        return -1;
    }

    // 簡單測試迴圈
    bool running = true;
    SDL_Event event;
    int red = 255, green = 0, blue = 0;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        red = (red + 1) % 256; // 簡單變色效果
        green = (green + 2) % 256;
        blue = (blue + 3) % 256;

        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, red-50, green-50, blue-50, 255);
        SDL_Rect test_rect = {200, 150, 300, 200};
        SDL_RenderFillRect(renderer, &test_rect);

        // TODO: 之後在這裡呼叫 CUI_RenderLabel(...)

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    CUI_Quit();
    printf("程式正常結束。\n");
    return 0;
}