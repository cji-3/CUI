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
 * \file draw.c
 * \author 林東頡
 * \brief 畫畫面專用。for painting drawing use only
 * \version 1.0.0
 * \date 2026-08-25
 */

#include <CUI_internal.h>
#include <CUI_draw.h>
#include <CUI_box.h>
#include <CUI_cell.h>
#include <CLS/CLS.h>
#include <stdbool.h>

#include <stdio.h>

#define _setRenderDrawColor(RENDERER,COLOR) SDL_SetRenderDrawColor(RENDERER,COLOR.r,COLOR.g,COLOR.b,COLOR.a)
#define _setFRect(FRECT,X,Y,W,H) do{(FRECT).x=X; (FRECT).y=Y; (FRECT).w=W; (FRECT).h=H;}while(0)
#define GAP 8

//---

void _drawButton(CUI_Button *button,SDL_FPoint pos){
	SDL_FRect fr={pos.x,pos.y,button->textW+12,button->textH+12};
	button->fr=fr;
	_setRenderDrawColor(_renderer,button->color1);
	SDL_RenderFillRect(_renderer,&fr);
	_setFRect(fr,fr.x+2,fr.y+2,fr.w-4,fr.h-4);
	_setRenderDrawColor(_renderer,button->color0);
	SDL_RenderFillRect(_renderer,&fr);
	_setFRect(fr,fr.x+4,fr.y+4,button->textW,button->textH);
	SDL_RenderTexture(_renderer,button->textTt,NULL,&fr);
}

//---

static bool _isQuit=false;
static bool _isDownLeft=false;

void _eventTreat(){
	_isDownLeft=false;

	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_EVENT_QUIT:
				_isQuit=true;
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				if(event.button.button==SDL_BUTTON_LEFT){
					_isDownLeft=true;
				}
				break;
			default:

				break;
		}
	}
}

void _render(){
	int i;
	for(i=0;i<CLS_Len(_boxList);i++){
		CUI_Box *box=*(CUI_Box**)CLS_Get(_boxList,i);
		CLS_List *boxDeCellList=box->cellList;

		/*box位置處理*/
		if(box->refBox==CUI_REFBOX_Q){
			box->fr.x=0; box->fr.y=0;
			box->fr.w=0; box->fr.h=0;
		}

		int boxDeCellNum=CLS_Len(boxDeCellList);
		int j;
		for(j=0;j<boxDeCellNum;j++){
			CUI_Cell *cell=*(CUI_Cell**)CLS_Get(boxDeCellList,j);
			switch(*(CUI_CellType*)cell){
				case CUI_CELLTYPE_LABEL:

					break;
				case CUI_CELLTYPE_BUTTON:{
					CUI_Button *button=(CUI_Button*)cell;

					SDL_FPoint pos;
					if(box->vhFlag==CUI_BOXVH_V){
						if(box->wOrH==CUI_BOXHWFLAG_MIN){
							if(j==0){
								pos.x=box->fr.x+GAP;
								pos.y=box->fr.y+GAP;
							}
							else{
								pos.x=box->fr.x+GAP;
								pos.y=box->fr.h + box->fr.y + GAP;
							}
							_drawButton(button,pos);
							box->fr.h=button->fr.h+button->fr.y;
						}
					}
					//HBox
					else{

					}

					if(_isDownLeft && button->clickLib){
						SDL_FPoint mp;
						SDL_GetMouseState(&mp.x,&mp.y);
						if(SDL_PointInRectFloat(&mp,&button->fr)){
							button->clickLib(button);
						}
					}

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
		SDL_SetRenderDrawColor(_renderer,100,100,100,255);
		SDL_RenderClear(_renderer);

		_eventTreat();
		_render();

		SDL_RenderPresent(_renderer);
	}
}