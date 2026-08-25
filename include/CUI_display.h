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
 * @file CUI_widgets.h
 * @author 林東頡
 * @brief 顯示型元件(非互動型元件)庫。display component(non interactive component) library.
 * @version 1.0.0
 * @date 2026-05-01
 */

/*
創建元件分為
- 簡單創建(Create)
- 完整創建(WholeCreate)
簡單創建只需輸入基本參數
完整創建需輸入所有參數
*/

#ifndef _CUI_display_H_
#define _CUI_display_H_

#include<stdbool.h>
#include<stdint.h>

//#include "CUI_def.h"

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t CUI_Color;

/**
 * \brief 顯示型元件之結構
 */
typedef struct{
	int pow_x;					/**< x座標 */
	int pow_y;					/**< y座標 */
	int w;						/**< 寬 */
	int h;						/**< 高 */
	const char* text;			/**< 文字 */
	int text_size;				/**< 文字大小 */
	CUI_Color text_color;		/**< 文字顏色(RGBA8888) */
	CUI_Color prospect_color;	/**< 前景色(RGBA8888) */
	CUI_Color background_color;	/**< 背景色(RGBA8888) */
	const char* font_path;		/**< 字體檔案(.ttf)路徑 */
	const char* image_path;		/**< 圖片路徑 */
	bool shown;					/**< 是否顯示 */
}CUI_Display;

#define CUI_TEXT_SIZE_DEFAULT 16	/**< 文字大小預設值 */
#define CUI_FONT_PATH_DEFAULT "C:\\Windows\\Fonts\\Arial\\arial.ttf"	/**< 字體檔案(.ttf)路徑預設值 */

//---

// void CUI_CreateLabel(int pow_x,int pow_y,const char* text,int text_size,uint32_t text_color);

// void CUI_WholeCreateLabel(int pow_x,int pow_y,const char* text,int text_size,uint32_t text_color);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif