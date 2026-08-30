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
 * \file CUI_draw.h
 * \author 林東頡
 * \brief 畫畫面專用。for painting drawing use only
 * \version 1.0.0
 * \date 2026-08-25
 */

#ifndef _CUI_DRAW_H_
#define _CUI_DRAW_H_

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief 畫畫面
 *
 * \since This function is available since CUI 1.0.0
 */
void CUI_Loop();

//設定C函數定義，使使用C++時也是如此
#ifdef __cplusplus
}
#endif

#endif