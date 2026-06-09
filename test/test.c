#include<stdbool.h>

#ifdef _WIN32
#include<windows.h>
#endif

#include "..\include\CUI.h"

int main() {
	CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);

	#ifdef _WIN32
	Sleep(1000);
	#endif

	CUI_Ctnr* Ctnr=CUI_CreateCtnr(VBOX);

	/*
	預想的CUI使用過程：

	建立視窗
	建立容器
	於各容器放置各種元件
	*/

	CUI_Quit();
	return 0;
}