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
 * \file CUI.c
 * \author 林東頡
 * \brief 初始化實作。init implementation.
 * \version 1.0.0
 * \date 2026-04-30
 */

#include <CUI_internal.h>
#include <CUI_box.h>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>


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

SDL_Window *_window=NULL;
SDL_Renderer *_renderer=NULL;
CLS_List *_boxList=NULL;
TTF_Font *_font=NULL;
CUI_Box *CUI_REFBOX_Q=NULL;
CUI_Box *CUI_REFBOX_W=NULL;
CUI_Box *CUI_REFBOX_A=NULL;
CUI_Box *CUI_REFBOX_S=NULL;

//初始化，創建所謂SDL的視窗和渲染器
int CUI_Init(const char *title,int w,int h){
	_window=SDL_CreateWindow(title,w,h,0);
	if(!_window) return 1;
	_renderer=SDL_CreateRenderer(_window,NULL);
	if(!_renderer){
		SDL_DestroyWindow(_window);
		return 2;
	}

	//init
	SDL_Init(SDL_INIT_AUDIO);
	TTF_Init();

	SDL_SetRenderVSync(_renderer,SDL_RENDERER_VSYNC_ADAPTIVE);

	// SDL_Surface *icon=IMG_Load(iconPath);
	// if(!icon) fprintf(stderr,"icon==NULL:%s\n",SDL_GetError());
	// SDL_SetWindowIcon(_window,icon);
	// SDL_DestroySurface(icon);

	_font=TTF_OpenFont(DEFAUTTO_FONT_PATH,DEFAUTO_TEXT_SIZE);
	if(!_font) fprintf(stderr,"font==NULL:%s\n",SDL_GetError());

	//init
	CLS_SetDeBug(CLS_SETDEBUG_FLAG_SING|CLS_SETDEBUG_FLAG_ERROR);
	_boxList=CLS_Create(sizeof(CUI_Box*));
	CUI_REFBOX_Q=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_W=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_A=(CUI_Box*)malloc(sizeof(CUI_Box*));
	CUI_REFBOX_S=(CUI_Box*)malloc(sizeof(CUI_Box*));

	return 0;
}

//退出視窗，這將釋放所有CUI資源
void CUI_Quit(){
	CLS_Free(&_boxList);
	free(CUI_REFBOX_Q);
	free(CUI_REFBOX_W);
	free(CUI_REFBOX_A);
	free(CUI_REFBOX_S);
	TTF_CloseFont(_font);
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