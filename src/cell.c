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
 * @file CUI_cell.c
 * @author 林東頡
 * @brief 元素、元件。cell、component.
 * @version 1.0.0
 * @date 2026-08-26
 */

#include <CUI_internal.h>
#include <CUI_cell.h>
#include <stdlib.h>
#include <SDL3_ttf/SDL_ttf.h>

const CUI_Color DEFAUTO_COLOR0={255,255,255,255};
const CUI_Color DEFAUTO_COLOR1={100,100,100,255};
const CUI_Color DEFAUTO_COLORT={0,0,0,255};

CUI_Cell *CUI_CreateButton(char *text){
	CUI_Cell *out=(CUI_Cell*)malloc(sizeof(CUI_Cell));
	out->type=CUI_CELLTYPE_BUTTON;
	out->_struct.button.text=text;
	out->_struct.button.text_size=DEFAUTO_TEXT_SIZE;
	out->_struct.button.color0=DEFAUTO_COLOR0;
	out->_struct.button.color1=DEFAUTO_COLOR1;
	out->_struct.button.colorT=DEFAUTO_COLORT;
	out->_struct.button.show=true;

	SDL_Surface *textSf=TTF_RenderText_Blended(_font,text,0,DEFAUTO_COLORT);
	SDL_Texture *textTt=SDL_CreateTextureFromSurface(_renderer,textSf);
	SDL_DestroySurface(textSf);
	out->_struct.button.w=textSf->w;
	out->_struct.button.h=textSf->h;
	out->_struct.button.textTt=textTt;

	return out;
}