/**
 * @file CUI_container.h
 * @author 林東頡
 * @brief 容器庫。container library.
 * @version 1.0.0
 * @date 2026-05-04
 */

#ifndef _CUI_CONTAINER_H_
#define _CUI_CONTAINER_H_

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef struct CUI_Container CUI_Container;

//容器模式
typedef enum{
	VBOX,
	HBOX
}CUI_ContainerMode;

CUI_Container* CUI_CreateContainer(CUI_ContainerMode mode);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif