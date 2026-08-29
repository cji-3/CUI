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
 * @file CUI_box.h
 * @author 林東頡
 * @brief 容器庫。box library.
 * @version 1.0.0
 * @date 2026-05-04
 */

#ifndef _CUI_BOX_H_
#define _CUI_BOX_H_

#include <CLS/CLS.h>
#include <stdint.h>
#include <stdbool.h>

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef struct CUI_Cell CUI_Cell;
typedef struct CUI_Box CUI_Box;

typedef enum{
	CUI_BOXHWFLAG_AUTO=-1,		/**< 根據內部元件調整大小 */
	CUIBOXHWFLAG_WINDOW=-2		/**< 根據視窗大小 */
}CUI_BoxWHFlag;

typedef struct CUI_Box{
	CUI_Box *refBox;
	char refBoxPos;
	CUI_BoxWHFlag show_w;	/**< 顯示的寬 */
	CUI_BoxWHFlag show_h;	/**< 顯示的高 */
	float x;
	float y;
	int w;					/**< 實際的寬(是給cell用的) */
	int h;					/**< 實際的高(是給cell用的) */
	bool show;
	CLS_List *cellList;		/**< 存放容器內的元件列表(CUI_Cell**) */
}CUI_Box;

/**
 * \brief 創建垂直容器
 * \param refBox 要相對於那個容器，然而CUI初始化時會產生四個偽容器，它們分別代表四個角落，名:CUI_REFBOX_Q、W、A、S(看鍵盤位置)!
 * \param refBoxPos 相對於該容器的上、下、左、右(w,s,a,d)
 * \param w 容器的寬。詳見CUI_BoxWHFlag，當然，你也可以輸入值!
 * \param h 容器的高。詳見CUI_BoxWHFlag，當然，你也可以輸入值!
 *
 * \since This function is available since CUI 1.0.0
 */
CUI_Box *CUI_CreateVBox(CUI_Box *refBox,char refBoxPos,CUI_BoxWHFlag w,CUI_BoxWHFlag h);
CUI_Box *CUI_CreateHBox();
void CUI_BoxAddCell(CUI_Box *box,CUI_Cell *cell);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif