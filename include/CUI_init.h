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
 * @file CUI_init.h
 * @author 林東頡
 * @brief 初始化庫。 initialize library.
 * @version 1.0.0
 * @date 2026-04-30
 */

#ifndef _CUI_INIT_H_
#define _CUI_INIT_H_

//#include "CUI_def.h"

#include<stdint.h>

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

/**
 * 視窗位置常數
 *
 * \sa CUI_Init
 */
extern int CUI_INIT_WINDOW_POS_CENTERED;	/**< 居中 */
extern int CUI_INIT_WINDOW_POS_UNDEFINED;	/**< 讓CUI自行決定 */

/**
 * 視窗模式常數
 *
 * \sa CUI_Init
 */
extern uint32_t CUI_INIT_WINDOW_MODE_SHOWN;					/**< 顯示視窗 */
extern uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN;			/**< 全螢幕視窗 */
extern uint32_t CUI_INIT_WINDOW_MODE_FULLSCREEN_DESKTOP;	/**< 桌面解析度的全螢幕視窗 */
extern uint32_t CUI_INIT_WINDOW_MODE_BORDERLESS;			/**< 無邊框 */
extern uint32_t CUI_INIT_WINDOW_MODE_RESIZABLE;				/**< 視窗可以調整大小 */
extern uint32_t CUI_INIT_WINDOW_MODE_MINIMIZED;				/**< 視窗最小化 */
extern uint32_t CUI_INIT_WINDOW_MODE_MAXIMIZED;				/**< 視窗最大化 */
extern uint32_t CUI_INIT_WINDOW_MODE_INPUT_GRABBED;			/**< 視窗已擷取輸入焦點 */

//---

/**
 * \brief 初始化，創建所謂SDL的視窗和渲染器
 *
 * \param window_title 視窗標題(UTF-8)
 * \param window_pos_x 視窗位置X座標(左上角)
 * \param window_pos_y 視窗位置Y座標(左上角)
 * \param window_w 視窗寬度
 * \param window_h 視窗高度
 * \param window_mode 視窗模式
 *
 * ---
 *
 * `window_pos_x 視窗X座標` y座標也是一樣的：
 *
 * - `CUI_INIT_WINDOW_POS_CENTERED`：居中
 *
 * - `CUI_INIT_WINDOW_POS_UNDEFINED`：讓CUI自行決定
 *
 * ---
 *
 * `window_mode` 視窗模式，可以是下列任一個，或是用位元或組合：
 *
 * - `CUI_INIT_WINDOW_MODE_SHOWN`：顯示視窗
 *
 * - `CUI_INIT_WINDOW_MODE_FULLSCREEN`：全螢幕視窗
 *
 * - `CUI_INIT_WINDOW_MODE_FULLSCREEN_DESKTOP`：桌面解析度的全螢幕視窗
 *
 * - `CUI_INIT_WINDOW_MODE_BORDERLESS`：無邊框
 *
 * - `CUI_INIT_WINDOW_MODE_RESIZABLE`：視窗可以調整大小
 *
 * - `CUI_INIT_WINDOW_MODE_MINIMIZED`：視窗最小化
 *
 * - `CUI_INIT_WINDOW_MODE_MAXIMIZED`：視窗最大化
 *
 * - `CUI_INIT_WINDOW_MODE_INPUT_GRABBED`：視窗已擷取輸入焦點
 *
 * ---
 *
 * \since This function is available since CUI 1.0.0
 */
int CUI_Init(const char* window_title,int window_pos_x,int window_pos_y,int window_w,int window_h,uint32_t window_mode);

/**
 * \brief 退出視窗，這將釋放所有CUI資源
 *
 * \since This function is available since CUI 1.0.0
 */
void CUI_Quit();

/**
 * \brief 取得視窗寬度
 *
 * \since This function is available since CUI 1.0.0
 */
int CUI_GetWindowWidth();

/**
 * \brief 取得視窗高度
 *
 * \since This function is available since CUI 1.0.0
 */
int CUI_GetWindowHeight();

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif