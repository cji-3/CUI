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
 * \file CUI_box.h
 * \author 林東頡
 * \brief 容器庫。box library.
 * \version 1.0.0
 * \date 2026-05-04
 */

#ifndef _CUI_BOX_H_
#define _CUI_BOX_H_

#include <CLS/CLS.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef struct CUI_Cell CUI_Cell;	/**< CUI_Cell就是一個指向CUI_Button或CUI_Label等等的元件 於是隨便拿了一個CUI_Button來表示 */
typedef struct CUI_Box CUI_Box;

typedef enum CUI_RefBoxVH{
	CUI_REFBOX_V,
	CUI_REFBOX_H,
}CUI_RefBoxVH;

/**
 * \brief
 *
 * \sa CUI_CreateVbox();
 */
typedef enum{
	CUI_BOXWHFLAG_MIN=-1,		/**< 最小寬度或高度，根據內部元件調整大小 */
	CUI_BOXWHFLAG_REF=-2,		/**< 繼承相對的容器寬度或高度,若無則取最小 */
	CUI_BOXWHFLAG_MAX=-3,		/**< 盡可能的大 */
	CUI_BOXWHFLAG_WIN=-5,		/**< 最大寬度或高度，根據視窗大小 */
}CUI_BoxWHFlag;

typedef enum{
	CUI_BOXVH_V,
	CUI_BOXVH_H,
}CUI_BoxVH;

typedef struct CUI_Box{
	CUI_BoxVH vhFlag;
	CUI_Box *refBox;			/**< 要相對於那個容器 */
	CUI_RefBoxVH refBoxPos;		/**< 相對於該容器的垂直或水平延伸 */
	CUI_BoxWHFlag hFlag;			/**< 高的旗標 */
	int *highAPArr;
	CUI_BoxWHFlag wFlag;			/**< 寬的旗標 */
	int *wideAPArr;
	SDL_FRect fr;
	bool show;
	CLS_List *cellList;			/**< 存放容器內的元件列表(CUI_Cell**) */
	CLS_List *maxBoxDeBoxList;	/**< 若是max的box的話就要此list記錄有那些box是在這個垂直或水平的地方 (CUI_Box**)*/
}CUI_Box;

/**
 * \brief 創建垂直容器
 * \param refBox 要相對於那個容器，然而CUI初始化時會產生四個偽容器，它們分別代表四個角落，名:CUI_REFBOX_Q、W、A、S(看鍵盤位置)!
 * \param refBoxPos 相對於該容器的垂直或水平延伸
 * \param high 容器的高。詳見CUI_BoxWHFlag，當然，你也可以輸入值!
 * \param highAPArr (high de alignw porportion array)對齊比例數組。詳見如下:
 * CUI_Box *box=CUI_NewHbox(CUI_REFBOX_Q,0,CUI_BOXWHFLAG_WIN,(int[]){1,0,1});
 * 假設該容器中有兩個cell，如此，便會型成
 *
 * |       [button1][button2]       |
 *
 * 的排板。1:0:1就是代表空隙的比例了!
 * 依此，若要靠右對齊就是1:0:0了!
 * 有n個cell就會有n+1個空隙，highAPArr就要有n+1項
 * 若輸入NULL則預設向上(左)對齊
 * \param wide 容器的寬。容器的高。詳見CUI_BoxWHFlag，當然，你也可以輸入值!
 * \param wideAPArr (high de alignw porportion array)對齊比例數組。詳見highAPArr的說明
 *
 * \since This function is available since CUI 1.0.0
 */
CUI_Box *CUI_NewVBox(CUI_Box *refBox,CUI_RefBoxVH refBoxPos,CUI_BoxWHFlag high,int highAPArr[],CUI_BoxWHFlag wide,int wideAPArr[]);

CUI_Box *CUI_NewHBox(CUI_Box *refBox,CUI_RefBoxVH refBoxPos,CUI_BoxWHFlag wide,int wideAPArr[],CUI_BoxWHFlag high,int highAPArr[]);

void CUI_BoxAddCell(CUI_Box *box,CUI_Cell *cell);

int CUI_GetBoxDeCellNum(CUI_Box *box);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif