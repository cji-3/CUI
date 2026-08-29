/*
 * Copyright (C) 2026 cji-3
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Or see <https://www.gnu.org/licenses/>.
 */

/**
 * @file CUI.c
 * @author 林東頡
 * @brief 初始化實作。init implementation.
 * @version 1.0.0
 * @date 2026-04-30
 */

#include <CUI_internal.h>
#include <CUI_box.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

// //視窗位置常數
// int CUI_INIT_WINDOW_POS_CENTERED=SDL_WINDOWPOS_CENTERED;
// int CUI_INIT_WINDOW_POS_UNDEFINED=SDL_WINDOWPOS_UNDEFINED;

// //視窗模式常數
// uint32_t CUI_INIT_WINDOW_MODE_SHOWN=				SDL_WINDOW_SHOWN;
// uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN=			SDL_WINDOW_FULLSCREEN;
// uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN_DESKTOP=	SDL_WINDOW_FULLSCREEN_DESKTOP;
// uint32_t CUI_INIT_WINDOW_MODE_BORDERLESS=			SDL_WINDOW_BORDERLESS;
// uint32_t CUI_INIT_WINDOW_MODE_RESIZABLE=			SDL_WINDOW_RESIZABLE;
// uint32_t CUI_INIT_WINDOW_MODE_MINIMIZED=			SDL_WINDOW_MINIMIZED;
// uint32_t CUI_INIT_WINDOW_MODE_MAXIMIZED=			SDL_WINDOW_MAXIMIZED;
// uint32_t CUI_INIT_WINDOW_MODE_INPUT_GRABBED=		SDL_WINDOW_INPUT_GRABBED;

//---

#define DEFAUTTO_FONT_PATH "C:/windows/fonts/msjh.ttc"

//靜態變數宣告，這些是函式全域可用的，它們透過CUI_internal.h來標記它們屬於外部變數
SDL_Window *_window=NULL;		/**< 存放window指標 */
SDL_Renderer *_renderer=NULL;	/**< 存放renderer指標 */
CLS_List *_boxList=NULL;		/**< 容器列表(CUI_Box**) */
TTF_Font *_font=NULL;

CUI_Box *CUI_REFBOX_Q;
CUI_Box *CUI_REFBOX_W;
CUI_Box *CUI_REFBOX_A;
CUI_Box *CUI_REFBOX_S;

//初始化，創建所謂SDL的視窗和渲染器
int CUI_Init(const char *title,int w,int h){
	//init
	CLS_SetDeBug(CLS_SETDEBUG_FLAG_SING|CLS_SETDEBUG_FLAG_ERROR);
	_boxList=CLS_Create(sizeof(CUI_Box*));
	CUI_REFBOX_Q=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_W=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_A=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_S=(CUI_Box*)malloc(sizeof(CUI_Box*));

	//init
	SDL_Init(SDL_INIT_AUDIO);
	TTF_Init();
	SDL_SetRenderVSync(_renderer,1);
	_font=TTF_OpenFont(DEFAUTTO_FONT_PATH,DEFAUTO_TEXT_SIZE);
	if(!_font) perror("font is NULL");

	if(!_window && !_renderer){
		_window=SDL_CreateWindow(title,w,h,0);
		_renderer=SDL_CreateRenderer(_window,NULL);

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

//退出視窗，這將釋放所有CUI資源
void CUI_Quit(){
	CLS_Free(&_boxList);
	free(CUI_REFBOX_Q);
	free(CUI_REFBOX_W);
	free(CUI_REFBOX_A);
	free(CUI_REFBOX_S);
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