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

#define _setRenderDrawColor(/*(SDL_Renderer*)*/RENDERER,/*(CUI_Color)*/COLOR)	\
SDL_SetRenderDrawColor(RENDERER,COLOR.r,COLOR.g,COLOR.b,COLOR.a)
#define _setFRect(/*(SDL_Frect)*/FRECT,X,Y,W,H) do{(FRECT).x=X; (FRECT).y=Y; (FRECT).w=W; (FRECT).h=H;}while(0)
#define GAP 8

//---

void _drawButton(CUI_Button *button){
	SDL_FRect fr=button->fr;

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
static bool _isRendering=true;
static bool _isDownLeft=false;

void _eventTreat(){
	_isRendering=false;
	_isDownLeft=false;

	SDL_Event event;
	if(SDL_WaitEvent(&event)){	//阻塞式
		do{
			switch(event.type){
				case SDL_EVENT_QUIT:
					_isQuit=true;
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					if(event.button.button==SDL_BUTTON_LEFT){
						_isDownLeft=true;
						_isRendering=true;
					}
					break;
				default:

					break;
			}
		}while(SDL_PollEvent(&event));
	}
}

// void _getBoxDeCellInfo(CUI_Box *box,float cellHArr[],float cellYArr[]){
// 	for(int cellIndex=0;cellIndex<)
// }

void _render(){
	for(int boxIndex=0;boxIndex<CLS_Len(_boxList);boxIndex++){	//boxIndex代表處理到第幾個box
		CUI_Box *box=*(CUI_Box**)CLS_Get(_boxList,boxIndex);
		CLS_List *boxDeCellList=box->cellList;

		/*box位置處理*/
		if(box->refBox==CUI_REFBOX_TOPLEFT){
			box->fr.x=0; box->fr.y=0;
		}
		else{	//refbox is true box
			if(box->refBoxPos==CUI_REFBOX_H){
				box->fr.x=box->refBox->fr.x+box->refBox->fr.w;
				box->fr.y=box->refBox->fr.y;
			}
			else{
				box->fr.y=box->refBox->fr.y+box->refBox->fr.h;
				box->fr.x=box->refBox->fr.x;
			}
		}

		//前置處理
		int boxDeCellListLen=CLS_Len(boxDeCellList);

		int *highAPArr=box->highAPArr;	//high de alignw porportion array 對齊比例列表
		if(!highAPArr){
			highAPArr=(int*)malloc(boxDeCellListLen*sizeof(int));
			memset(highAPArr,0,boxDeCellListLen);
			highAPArr[boxDeCellListLen-1]=1;	//{0,0,...,1}靠左(上)對齊
		}

		//取得box裡的所有cell的高和y座標
		float cellHArr[boxDeCellListLen],cellYArr[boxDeCellListLen];
		for(int cellIndex=0;cellIndex<boxDeCellListLen;cellIndex++){	//cellIndex代表處理到box中的第幾個cell
			CUI_Cell *cell=*(CUI_Cell**)CLS_Get(boxDeCellList,cellIndex);
			cell->fr.x=box->fr.x+GAP;
			cellHArr[cellIndex]=(*(CUI_Cell**)CLS_Get(boxDeCellList,cellIndex))->fr.h;
		}

		int winH;
		SDL_GetWindowSize(_window,NULL,&winH);

		//box high treat
		switch(box->hFlag){
			case CUI_BOXWHFLAG_MIN:
				if(box->vhFlag==CUI_BOXVH_V)
					box->fr.h=_floatArrSum(boxDeCellListLen,cellHArr)+(boxDeCellListLen+1)*GAP;
				break;
			case CUI_BOXWHFLAG_WIN:
				if(box->vhFlag==CUI_BOXVH_V)
					box->fr.h=winH;
				break;
			case CUI_BOXWHFLAG_REF:
				if(box->vhFlag==CUI_BOXVH_V)
					box->fr.h=box->refBox->fr.h;
				break;
			case CUI_BOXWHFLAG_MAX:
				if(box->vhFlag==CUI_BOXVH_V){
					float hSum=0;
					for(int i=0;i<CLS_Len(box->maxBoxDeBoxList);i++){
						hSum+=(*(CUI_Box**)CLS_Get(box->maxBoxDeBoxList,i))->fr.h;
					}
					box->fr.h=winH-hSum;
				}
				break;
			default:
				box->fr.y=box->hFlag;
				break;
		}

		box->fr.w=0;

		//cell處理
		for(int cellIndex=0;cellIndex<boxDeCellListLen;cellIndex++){	//cellIndex代表處理到box中的第幾個cell
			CUI_Cell *cell=*(CUI_Cell**)CLS_Get(boxDeCellList,cellIndex);

			switch(*(CUI_CellType*)cell){	//第一個成員都是type(cell->com.type)
				case CUI_CELLTYPE_LABEL:

					break;
				case CUI_CELLTYPE_BUTTON:{
					CUI_Button *button=(CUI_Button*)cell;

					//函式
					if(_isDownLeft && button->clickLib){
						SDL_FPoint mp;
						SDL_GetMouseState(&mp.x,&mp.y);
						if(SDL_PointInRectFloat(&mp,&button->fr)){
							button->clickLib(button);
						}
					}

					if(box->vhFlag==CUI_BOXVH_V){	//VBox
						if(box->hFlag==CUI_BOXWHFLAG_MIN){
							if(cell->fr.w+2*GAP>box->fr.w) box->fr.w=cell->fr.w+2*GAP;

							if(cellIndex==0) button->fr.y=box->fr.y+GAP;
							else button->fr.y=cellHArr[cellIndex-1]+cellYArr[cellIndex-1]+GAP;
							cellYArr[cellIndex]=button->fr.y;
						}
						else{	//win,max,num,ref
							if(cell->fr.w+2*GAP>box->fr.w) box->fr.w=cell->fr.w+2*GAP;

							float cellHSum=_floatArrSum(boxDeCellListLen,cellHArr);
							int aslSum=_intArrSum(boxDeCellListLen+1,highAPArr);
							if(!aslSum) aslSum=1;
							float cellUpGap=((float)highAPArr[cellIndex]/aslSum)*(box->fr.h-((boxDeCellListLen+1)*GAP+cellHSum));
							button->fr.y=GAP+cellUpGap+((cellIndex==0)?0:cellYArr[cellIndex-1]+cellHArr[cellIndex-1]);
							cellYArr[cellIndex]=button->fr.y;
						}
						_drawButton(button);
					}
					else{	//HBox

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
			SDL_SetRenderDrawColor(_renderer,255,boxIndex*100,0,255);
			SDL_RenderRect(_renderer,&box->fr);
		}
	}
}

void CUI_Loop(){
	while(!_isQuit){
		if(_isRendering){	//需要渲染時才渲染
			SDL_SetRenderDrawColor(_renderer,100,100,100,255);
			SDL_RenderClear(_renderer);
			_render();
			SDL_RenderPresent(_renderer);

			log("rendering");	//
		}
		_eventTreat();
	}
}