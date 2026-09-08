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
 * \file box.c
 * \author 林東頡
 * \brief 容器庫實作。Box library implementation.
 * \version 1.0.0
 * \date 2026-05-04
 */

#include <CUI_internal.h>
#include <CUI_box.h>
#include <CUI_cell.h>
#include <stdlib.h>

CUI_Box *CUI_NewVBox(CUI_Box *refBox,CUI_RefBoxVH refBoxPos,CUI_BoxWHFlag highFlag,int highAPArr[],CUI_BoxWHFlag wideFlag,int wideAPArr[]){
	CUI_Box *out=(CUI_Box*)malloc(sizeof(CUI_Box));
	out->show=true;
	out->refBox=refBox;
	out->refBoxPos=refBoxPos;
	out->hFlag=highFlag;
	out->highAPArr=highAPArr;
	out->wFlag=wideFlag;
	out->wideAPArr=wideAPArr;
	out->vhFlag=CUI_BOXVH_V;
	out->cellList=CLS_Create(sizeof(CUI_Cell*));
	CLS_Psh(_boxList,&out);

	if(highFlag==CUI_BOXWHFLAG_MAX) out->maxBoxDeBoxList=CLS_Create(sizeof(CUI_Box*));
	else out->maxBoxDeBoxList=NULL;
	if(refBox->hFlag==CUI_BOXWHFLAG_MAX && refBoxPos==CUI_REFBOX_V){
		if(highFlag==CUI_BOXWHFLAG_WIN ) return NULL;	//錯誤
		CLS_Psh(refBox->maxBoxDeBoxList,&out);
	}
	return out;
}