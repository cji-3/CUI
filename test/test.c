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

/*
SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window=SDL_CreateWindow("UI test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,360,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);

	//事件輪詢
	bool quit=false;	//退出?
	while(!quit){	//不退出就循環
		SDL_Event event;
		while(SDL_PollEvent(&event)){	//讀取事件直到沒有事件
			switch(event.type){ //事件處理
				case SDL_QUIT:
					quit=true;
			}
		}
	}

	//銷毀並退出
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
*/