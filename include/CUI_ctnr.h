/**
 * @file CUI_Ctnr.h
 * @author 林東頡
 * @brief 容器庫。Ctnr library.
 * @version 1.0.0
 * @date 2026-05-04
 */

#ifndef _CUI_Ctnr_H_
#define _CUI_Ctnr_H_

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
 * \return 容器指標
 *
 * \since This function is available since CUI 1.0.0
 */
CUI_Ctnr* CUI_CreateCtnr(uint16_t x,uint16_t y,CUI_CtnrMode mode);

void CUI_CtnrAdd(CUI_Ctnr* ctnr,void* Widgets);

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif