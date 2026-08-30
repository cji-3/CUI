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
 * \file CUI_other.c
 * \author 林東頡
 * \brief 雜項。other.
 * \version 1.0.0
 * \date 2026-08-26
 */

#include <CUI_internal.h>
#include <CUI_other.h>

CUI_Color *CUI_RGBA8888(uint8_t r,uint8_t g,uint8_t b,uint8_t a){
	CUI_Color *out=(CUI_Color*)malloc(sizeof(CUI_Color));
	out->r=r;
	out->g=g;
	out->b=b;
	out->a=a;
	return out;
}