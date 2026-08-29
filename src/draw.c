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
 * @file draw.c
 * @author 林東頡
 * @brief 畫畫面專用。for painting drawing use only
 * @version 1.0.0
 * @date 2026-08-25
 */

#include <CUI_internal.h>
#include <CUI_draw.h>
#include <CUI_box.h>
#include <CUI_cell.h>
#include <CLS/CLS.h>
#include <stdbool.h>

#include <stdio.h>

#define SDLCUI_SetRenderDrawColor(RENDERER,COLOR) SDL_SetRenderDrawColor(RENDERER,COLOR.r,COLOR.g,COLOR.b,COLOR.a)
#define SDLCUI_SetFRect(FRECT,X,Y,W,H) do{FRECT.x=X; FRECT.y=Y; FRECT.w=W; FRECT.h=H;}while(0)
#define GAP 10

static bool _isQuit=false;

void _eventTreat(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_EVENT_QUIT:
				_isQuit=true;
				break;
			default:

				break;
		}
	}
}

void _render(){
	int i;
	for(i=0;i<CLS_Len(_boxList);i++){
		CUI_Box box=**(CUI_Box**)CLS_Get(_boxList,i);
		if(box.refBox==CUI_REFBOX_Q){
			box.x=GAP; box.y=GAP;
		}

		CLS_List *boxDeCellList=box.cellList;
		int j;
		for(j=0;j<CLS_Len(boxDeCellList);j++){
			CUI_Cell cell=**(CUI_Cell**)CLS_Get(boxDeCellList,j);
			switch(cell.type){
				case CUI_CELLTYPE_LABEL:

					break;
				case CUI_CELLTYPE_BUTTON:{
					CUI_Button button=cell._struct.button;
					SDL_FRect fr={box.x,box.y,button.w,button.h};
					SDLCUI_SetRenderDrawColor(_renderer,button.color1);
					SDL_RenderFillRect(_renderer,&fr);
					SDLCUI_SetFRect(fr,fr.x+2,fr.y+2,fr.w-2,fr.h-2);
					SDLCUI_SetRenderDrawColor(_renderer,button.color0);
					SDL_RenderFillRect(_renderer,&fr);

					break;
				}
				case CUI_CELLTYPE_BLOCK:

					break;
				default:

					break;
			}
		}
	}
}

void CUI_Loop(){
	while(!_isQuit){
		SDL_SetRenderDrawColor(_renderer,150,150,150,255);
		SDL_RenderClear(_renderer);

		_eventTreat();
		_render();

		SDL_RenderPresent(_renderer);
	}
}