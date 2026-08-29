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
 * @file CUI.h
 * @author 林東頡
 * @brief 此作為整合各標頭檔之用途。This Is Used For Integrating Various Header Files.
 * @version 1.0.0
 * @date 2026-04-30
 */

/*
函式命名風格：
依據SDL函式命名風格
如**CUI_Init()**如同**SDL_Init()**
常數命名風格：
CUI_WINDOW_XY_MIDDLE
用於WINDOW的位置的常數 表示中間
*/

/*
我們預設您沒有在您的專案使用SDL的需求。
若有在您的專案使用SDL的需求，則請**#define CUI_HAVE_SDL**，
並使用CUI_HaveInputRenderer()函式傳入您的渲染器。
並可使用許多進階功能(如事件管理)。
*/

#ifndef _CUI_H_
#define _CUI_H_

#include <CUI_init.h>
#include <CUI_draw.h>
#include <CUI_box.h>
#include <CUI_cell.h>
#include <CUI_other.h>

#endif