#include "../include/CUI.h"
#include "../extern/SDL/include/SDL.h"
#include<stdbool.h>

int main(int argc,char* argv[]) {
	CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);

	SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { //按x退出
                running = false;
            }
        }

        // 可以在這裡呼叫未來的 CUI_Render()
        SDL_Delay(16); // 簡單限制一下 CPU 使用率 (約 60 FPS)
    }

	CUI_Quit();
	return 0;
}