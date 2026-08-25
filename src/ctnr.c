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
 * @file CUI_Ctnr.c
 * @author 林東頡
 * @brief 容器庫實作。Ctnr library implementation.
 * @version 1.0.0
 * @date 2026-05-04
 */

#include<stdlib.h>
#include "CUI_ctnr.h"
#include "../extern/CLS/include/CLS.h"

//容器結構
struct CUI_Ctnr{
	CUI_CtnrMode mode;	/**< 方向模式 */
	char RelativePos;	/**< 相對位置 */
	uint16_t x;
	uint16_t y;
	uint16_t w;
	uint16_t h;
	CLS_List* list;		/**< 存放容器內的元件資料 */
};

//創建容器
CUI_Ctnr* CUI_CtnrCreate(char RelativePos,CUI_CtnrMode mode){
	// CUI_Ctnr* out=(CUI_Ctnr*)malloc(sizeof(CUI_Ctnr));
	// out->x=x;
	// out->y=y;
	// out->w=0;
	// out->h=0;
	// out->mode=mode;

	// return out;
}