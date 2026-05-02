/**
 * @file CUI_widgets.h
 * @author 林東頡
 * @brief 元件庫。Widgets library.
 * @version 1.0.0
 * @date 2026-05-01
 */

#ifndef _CUI_widgets_H_
#define _CUI_widgets_H_

#include<stdbool.h>

//#include "CUI_def.h"

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

typedef strcat{
	int x;					/**< x座標 */
	int y;					/**< y座標 */
	int w;					/**< 寬 */
	int h;					/**< 高 */
	const char* text;		/**< 文字 */
	SDL_Color prospect;		/**< 前景色 */
	SDL_Color background;	/**< 背景色 */
	const char* image;		/**< 圖片路徑 */
	bool shown;				/**< 是否顯示 */
}CUI_Display;

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif