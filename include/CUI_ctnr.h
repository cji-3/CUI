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
 * @file CUI_Ctnr.h
 * @author 林東頡
 * @brief 容器庫。Ctnr library.
 * @version 1.0.0
 * @date 2026-05-04
 */

#ifndef _CUI_Ctnr_H_
#define _CUI_Ctnr_H_

#include<stdint.h>

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef struct CUI_Ctnr CUI_Ctnr;

//容器模式
typedef enum{
	VBOX,	/**< 垂直 */
	HBOX	/**< 水平 */
}CUI_CtnrMode;

/**
 * \brief 創建容器
 *
 * 創建容器相對於
 *
 * 左上、右上	'q'、'w'
 *
 * 左下、右下	'a'、's'
 *
 * 即鍵盤布局!
 *
 * \param RelativePosition 相對位置
 * \param mode 容器模式
 * \return 容器指標
 *
 * \since This function is available since CUI 1.0.0
 */
CUI_Ctnr* CUI_CtnrCreate(char RelativePos,CUI_CtnrMode mode);

void CUI_CtnrAdd(CUI_Ctnr* ctnr,void* Widgets);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif