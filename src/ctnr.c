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
CUI_Ctnr* CUI_CreateCtnr(uint16_t x,uint16_t y,CUI_CtnrMode mode){
	CUI_Ctnr* out=(CUI_Ctnr*)malloc(sizeof(CUI_Ctnr));
	out->x=x;
	out->y=y;
	out->w=0;
	out->h=0;
	out->mode=mode;

	return out;
}