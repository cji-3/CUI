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
 * \file cell.h
 * \author 林東頡
 * \brief 元素、元件。cell、component.
 * \version 1.0.0
 * \date 2026-08-26
 */

/*
創建元件分為
- 簡單創建(Create)
- 完整創建(_P)
簡單創建只需輸入基本參數
完整創建需輸入所有參數
*/

#ifndef _CUI_CELL_H_
#define _CUI_CELL_H_

#include <CUI_box.h>
#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdint.h>

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef SDL_Color CUI_Color;

typedef enum{
	CUI_CELLTYPE_LABEL,
	CUI_CELLTYPE_BUTTON,
	CUI_CELLTYPE_BLOCK
}CUI_CellType;

//---

typedef struct{
	int w;						/**< 寬 */
	int h;						/**< 高 */
	const char *text;			/**< 文字 */
	int text_size;				/**< 文字大小 */
	CUI_Color color0;			/**< 前景色(RGBA8888) */
	CUI_Color color1;			/**< 背景色(RGBA8888) */
	CUI_Color colorT;			/**< 文字顏色(RGBA8888) */
	bool show;					/**< 是否顯示 */
}CUI_Label;

typedef struct{
	const char *text;			/**< 文字 */
	SDL_FRect fr;				/**< 範圍 */
	SDL_Texture *textTt;
	int textW;
	int textH;
	int textSize;				/**< 文字大小 */
	CUI_Color color0;			/**< 前景色(RGBA8888) */
	CUI_Color color1;			/**< 背景色(RGBA8888) */
	CUI_Color colorT;			/**< 文字顏色(RGBA8888) */
	bool show;					/**< 是否顯示 */
	void (*clickLib)(CUI_Cell*);
}CUI_Button;

typedef struct{
	int w;						/**< 寬 */
	int h;						/**< 高 */
	CUI_Color color0;			/**< 前景色(RGBA8888) */
	CUI_Color color1;			/**< 背景色(RGBA8888) */
	bool show;					/**< 是否顯示 */
}CUI_Block;

//---

typedef union{
	CUI_Label label;
	CUI_Button button;
	CUI_Block block;
}CUI_CellStruct;

/**
 * \brief 元件(cell)之結構
 */
typedef struct CUI_Cell{
	CUI_CellType type;			/**< 類型 */
	CUI_CellStruct _struct;		/**< 對應結構 */
}CUI_Cell;

//---

CUI_Cell *CUI_CreateButton(char *text,void (*clickLib)(CUI_Cell*));
void CUI_SetButtonText(CUI_Cell *button,const char *text);
CUI_Cell *CUI_CreateBlock(int w,int h);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif

//	int pow_x;					/**< x座標 */
//	int pow_y;					/**< y座標 */
//	int w;						/**< 寬 */
//	int h;						/**< 高 */
//	const char *text;			/**< 文字 */
//	int text_size;				/**< 文字大小 */
//	CUI_Color color0;			/**< 前景色(RGBA8888) */
//	CUI_Color color1;			/**< 背景色(RGBA8888) */
//	CUI_Color colorT;			/**< 文字顏色(RGBA8888) */
//	bool show;					/**< 是否顯示 */
//	void *other;				/**< 其他 */
//	const char *font_path;		/**< 字體檔案(.ttf)路徑 */
//	const char *image_path;		/**< 圖片路徑 */