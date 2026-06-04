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

struct CUI_Ctnr{
	CUI_CtnrMode mode;	//方向模式
	CLS_List* list;		//存放容器內的元件資料
};

//創建容器
CUI_Ctnr* CUI_CreateCtnr(CUI_CtnrMode mode){
	CUI_Ctnr* out=(CUI_Ctnr*)malloc(sizeof(CUI_Ctnr));
	out->mode=mode;

	return out;
}