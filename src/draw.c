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

#define _setRenderDrawColor(/*(SDL_Renderer*)*/RENDERER,/*(CUI_Color)*/COLOR)	\
SDL_SetRenderDrawColor(RENDERER,COLOR.r,COLOR.g,COLOR.b,COLOR.a)
#define _setFRect(/*(SDL_Frect)*/FRECT,X,Y,W,H) do{(FRECT).x=X; (FRECT).y=Y; (FRECT).w=W; (FRECT).h=H;}while(0)
#define GAP 8

//---

void _drawButton(CUI_Button *button,SDL_FPoint pos){
	button->com.fr.x=pos.x;
	button->com.fr.y=pos.y;
	SDL_FRect fr=button->com.fr;

	_setRenderDrawColor(_renderer,button->color1);
	SDL_RenderFillRect(_renderer,&fr);
	_setFRect(fr,fr.x+2,fr.y+2,fr.w-4,fr.h-4);
	_setRenderDrawColor(_renderer,button->color0);
	SDL_RenderFillRect(_renderer,&fr);
	_setFRect(fr,fr.x+4,fr.y+4,button->textW,button->textH);
	SDL_RenderTexture(_renderer,button->textTt,NULL,&fr);
}

int _intArrSum(int n,int *arr){
	int out=0;
	for(int i=0;i<n;i++) out+=arr[i];
	return out;
}

float _floatArrSum(int n,float *arr){
	float out=0;
	for(int i=0;i<n;i++) out+=arr[i];
	return out;
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
	for(int boxIndex=0;boxIndex<CLS_Len(_boxList);boxIndex++){	//i在這裡代表處理到第幾個box
		CUI_Box *box=*(CUI_Box**)CLS_Get(_boxList,boxIndex);
		CLS_List *boxDeCellList=box->cellList;

		/*box位置處理*/
		if(box->refBox==CUI_REFBOX_Q){
			box->fr.x=0; box->fr.y=0;
			box->fr.w=0; box->fr.h=0;
		}

		int boxDeCellListLen=CLS_Len(boxDeCellList);
		for(int cellIndex=0;cellIndex<boxDeCellListLen;cellIndex++){	//j在這裡代表處理到box中的第幾個cell
			CUI_Cell *cell=*(CUI_Cell**)CLS_Get(boxDeCellList,cellIndex);

			switch(*(CUI_CellType*)cell){	//第一個成員都是type(cell->com.type)
				case CUI_CELLTYPE_LABEL:

					break;
				case CUI_CELLTYPE_BUTTON:{
					CUI_Button *button=(CUI_Button*)cell;

					SDL_FPoint pos;
					if(box->vhFlag==CUI_BOXVH_V){	//VBox
						if(box->wOrH==CUI_BOXWHFLAG_MIN){
							pos.x=box->fr.x+GAP;
							if(cellIndex==0) pos.y=box->fr.y+GAP;
							else pos.y=box->fr.h + box->fr.y + GAP;

							if(button->com.fr.w+2*GAP>box->fr.w) box->fr.w=button->com.fr.w+2*GAP;
							box->fr.h=button->com.fr.h+button->com.fr.y+GAP;
						}
						else if(box->wOrH==CUI_BOXWHFLAG_WIN){
							int *asl=box->alignwScaleList;	//alignwScaleList 對齊比例列表
							if(!asl){
								asl=(int*)malloc(boxDeCellListLen*sizeof(int));
								memset(asl,0,boxDeCellListLen);
								asl[boxDeCellListLen-1]=1;	//{0,0,...,1}靠左(上)對齊
							}

							int winH;
							SDL_GetWindowSize(_window,NULL,&winH);
							box->fr.h=winH;
							pos.x=box->fr.x+GAP;
							if(button->com.fr.w+2*GAP>box->fr.w) box->fr.w=button->com.fr.w+2*GAP;

							//取得box裡的所有cell的高和y座標
							float cellHArr[boxDeCellListLen],cellYArr[boxDeCellListLen];
							for(int i=0;i<boxDeCellListLen;i++){
								cellHArr[i]=(*(CUI_Button**)CLS_Get(boxDeCellList,i))->com.fr.h;
								cellYArr[i]=(*(CUI_Button**)CLS_Get(boxDeCellList,i))->com.fr.y;
							}

							float cellHSum=_floatArrSum(boxDeCellListLen,cellHArr);
							int aslSum=_intArrSum(boxDeCellListLen+1,asl);
							if(!aslSum) aslSum=1;
							float cellUpGap=((float)asl[cellIndex]/aslSum)*(winH-((boxDeCellListLen+1)*GAP+cellHSum));
							pos.y=GAP+cellUpGap+((cellIndex==0)?0:cellYArr[cellIndex-1]+cellHArr[cellIndex-1]);
						}
						_drawButton(button,pos);
					}
					else{	//HBox

					}

					if(_isDownLeft && button->clickLib){
						SDL_FPoint mp;
						SDL_GetMouseState(&mp.x,&mp.y);
						if(SDL_PointInRectFloat(&mp,&button->com.fr)){
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
		if(_debugShowBoxKnow){
			SDL_SetRenderDrawColor(_renderer,255,0,0,255);
			SDL_RenderRect(_renderer,&box->fr);
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