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
 * \file CUI_cell.c
 * \author 林東頡
 * \brief 元素、元件。cell、component.
 * \version 1.0.0
 * \date 2026-08-26
 */

#include <CUI_internal.h>
#include <CUI_cell.h>
#include <stdlib.h>
#include <SDL3_ttf/SDL_ttf.h>

const CUI_Color DEFAUTO_COLOR0={150,150,150,255};
const CUI_Color DEFAUTO_COLOR1={0,0,0,255};
const CUI_Color DEFAUTO_COLORT={0,0,0,255};

CUI_Button *CUI_CreateButton(char *text,void (*clickLib)(CUI_Button*)){
	CUI_Button *out=(CUI_Button*)malloc(sizeof(CUI_Button));
	out->com.type=CUI_CELLTYPE_BUTTON;
	out->text=text;
	out->textSize=DEFAUTO_TEXT_SIZE;
	out->color0=DEFAUTO_COLOR0;
	out->color1=DEFAUTO_COLOR1;
	out->colorT=DEFAUTO_COLORT;
	out->show=true;
	out->clickLib=clickLib;

	//文字貼圖,寬高之處理
	SDL_Surface *textSf=TTF_RenderText_Blended(_font,text,0,DEFAUTO_COLORT);
	SDL_Texture *textTt=SDL_CreateTextureFromSurface(_renderer,textSf);
	SDL_DestroySurface(textSf);
	out->textW=textTt->w;
	out->textH=textTt->h;
	out->textTt=textTt;

	out->com.fr.w=textTt->w+12;
	out->com.fr.h=textTt->h+12;

	return out;
}

int CUI_ButtonRenew(CUI_Button *button){
	SDL_DestroyTexture(button->textTt);
	//文字貼圖,寬高之處理
	SDL_Surface *textSf=TTF_RenderText_Blended(_font,button->text,0,DEFAUTO_COLORT);
	SDL_Texture *textTt=SDL_CreateTextureFromSurface(_renderer,textSf);
	SDL_DestroySurface(textSf);
	button->textW=textTt->w;
	button->textH=textTt->h;
	button->textTt=textTt;

	button->com.fr.w=textTt->w+12;
	button->com.fr.h=textTt->h+12;

	return 0;
}