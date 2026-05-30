#include<stdbool.h>

#ifdef _WIN32
#include<windows.h>
#endif

#include "CUI.h"

int main() {
	CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);

	#ifdef _WIN32
	Sleep(1000);
	#endif

	/*
	預想的CUI使用過程：

	建立視窗
	建立父容器
	於父容器中建立子容器
	於各子容器
	*/

	CUI_Quit();
	return 0;
}