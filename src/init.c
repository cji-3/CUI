/**
 * @file CUI.c
 * @author 林東頡
 * @brief 初始化實作。init implementation.
 * @version 1.0.0
 * @date 2026-04-30
 */

#include "../include/CUI_init.h"
//#include "../extern/SDL/include/CUI_def.h"
#include "../extern/SDL/include/SDL.h"

//視窗位置常數
int CUI_INIT_WINDOW_POS_CENTERED=SDL_WINDOWPOS_CENTERED;
int CUI_INIT_WINDOW_POS_UNDEFINED=SDL_WINDOWPOS_UNDEFINED;

//視窗模式常數
uint32_t CUI_INIT_WINDOW_MODE_SHOWN=				SDL_WINDOW_SHOWN;
uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN=			SDL_WINDOW_FULLSCREEN;
uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN_DESKTOP=	SDL_WINDOW_FULLSCREEN_DESKTOP;
uint32_t CUI_INIT_WINDOW_MODE_BORDERLESS=			SDL_WINDOW_BORDERLESS;
uint32_t CUI_INIT_WINDOW_MODE_RESIZABLE=			SDL_WINDOW_RESIZABLE;
uint32_t CUI_INIT_WINDOW_MODE_MINIMIZED=			SDL_WINDOW_MINIMIZED;
uint32_t CUI_INIT_WINDOW_MODE_MAXIMIZED=			SDL_WINDOW_MAXIMIZED;
uint32_t CUI_INIT_WINDOW_MODE_INPUT_GRABBED=		SDL_WINDOW_INPUT_GRABBED;

//---

//靜態變數宣告
static SDL_Window* _window=NULL;		/**< 存放window指標 */
static SDL_Renderer* _renderer=NULL;	/**< 存放renderer指標 */

//初始化，創建所謂SDL的視窗和渲染器
int CUI_Init(const char* window_title,int window_pos_x,int window_pos_y,int window_w,int window_h,uint32_t window_mode){
	if(!_window && !_renderer){
		SDL_Init(SDL_INIT_EVERYTHING);
		_window=SDL_CreateWindow(window_title,window_pos_x,window_pos_y, window_w,window_h,window_mode);
		_renderer=SDL_CreateRenderer(_window,-1,SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);

		return !_window || !_renderer;
	}
	else{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		_window=NULL;
		_renderer=NULL;

		return -1;
	}
}

//取得渲染器
SDL_Renderer* CUI_GetRenderer(void) {
    return _renderer;
}

SDL_Window* CUI_GetWindow(void) {
    return _window;
}

//退出視窗，這將釋放所有CUI資源
void CUI_Quit(){
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

//取得視窗寬度
int CUI_GetWindowWidth(){
    int w;
    SDL_GetWindowSize(_window,&w,NULL);
    return w;
}

//取得視窗高度
int CUI_GetWindowHeight(){
    int h;
    SDL_GetWindowSize(_window,NULL,&h);
    return h;
}