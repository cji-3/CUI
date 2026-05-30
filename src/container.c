/**
 * @file CUI_container.c
 * @author 林東頡
 * @brief 容器庫實作。container library implementation.
 * @version 1.0.0
 * @date 2026-05-04
 */

#include<stdlib.h>
#include "CUI_container.h"
#include "../extern/CLS/include/CLS.h"

struct CUI_Container{
	CUI_ContainerMode mode;
	CLS_List* list;
};

CUI_Container* CUI_CreateContainer(CUI_ContainerMode mode){
	CUI_Container* out=(CUI_Container*)malloc(sizeof(CUI_Container));
	out->mode=mode;
}