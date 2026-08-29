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
 * @file box.c
 * @author 林東頡
 * @brief 容器庫實作。Box library implementation.
 * @version 1.0.0
 * @date 2026-05-04
 */

#include <CUI_internal.h>
#include <CUI_box.h>
#include <CUI_cell.h>
#include <stdlib.h>

CUI_Box *CUI_CreateVBox(CUI_Box *refBox,char refBoxPos,CUI_BoxWHFlag w,CUI_BoxWHFlag h){
	CUI_Box *out=(CUI_Box*)malloc(sizeof(CUI_Box));
	out->refBox=refBox;
	out->refBoxPos=refBoxPos;
	out->show_w=w;
	out->show_h=h;
	out->w=0;
	out->h=0;
	out->cellList=CLS_Create(sizeof(CUI_Cell*));
	CLS_Psh(_boxList,&out);
	return out;
}

void CUI_BoxAddCell(CUI_Box *box,CUI_Cell *cell){
	CLS_Psh(box->cellList,&cell);
}