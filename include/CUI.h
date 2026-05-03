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
CIU_WINDOW_XY_MIDDLE
用於WINDOW的位置的常數 表示中間
*/

/*
我們預設您沒有在您的專案使用SDL的需求。
若有在您的專案使用SDL的需求，則請**#define CUI_HAVE_SDL**，
並使用CUI_HaveInputRenderer()函式傳入您的渲染器。
並可使用許多進階功能(如事件管理)。
*/

/*
# CUI：

![Logo](./document/CUI_LOGO_64x64.png)

## C語言使用者介面UI函式庫

開發與維護：CJI 公司 (中華民國台灣省彰化縣)

作者：

- 林東頡 (綽號：CJI)
- 賴洧霖 (weilinlai)

版本：1.0.0

## 著作權所有 (C) 2026 CJI 公司。

本程式碼採用「創用 CC 姓名標示 4.0 國際版本」進行授權 (CC BY 4.0)。

### 您可以自由地：

- 分享：以任何媒介或格式重製及散布本程式碼。
- 修改：在任何目的下，改作、轉變本程式碼或以此為基礎進行創作。

### 必須遵守下列條件：

- 姓名標示：您必須註明作者出處，並提供授權條款的連結。
- 禁止冒名：嚴禁聲稱本程式碼為您個人之原創作品。

---

# CUI：

![Logo](./document/CUI_LOGO_64x64.png)

## C code User Interface (UI) Function Library

Developed and Maintained by: CJI Corporation (Changhua County, Taiwan Province, Republic of China)

Author:

- 林東頡(Lin Dong-Jie) (Nickname: CJI)
- 賴洧霖(Lai Wei-Lin)

Version: 1.0.0


## Copyright (C) 2026 CJI Corporation.

This code is licensed under the Creative Commons Attribution 4.0

International License (CC BY 4.0).

### You are free to:

- Share: Copy and redistribute the material in any medium or format.
- Adapt: Remix, transform, and build upon the material for any purpose.

### Under the following terms:

- Attribution: You must give appropriate credit and provide a link to the license.
- Ownership: Claiming this code as your own original work is strictly prohibited.
*/

#ifndef _CUI_H_
#define _CUI_H_

#include "CUI_init.h"
#include "CUI_def.h"
#include "CUI_display.h"

#endif