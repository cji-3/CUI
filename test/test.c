#include<stdbool.h>

#ifdef _WIN32
#include<windows.h>
#endif

#include "..\include\CUI.h"

int main(){
	CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);
	/*
	創建容器相對於
	左上、中上、右上	'q'、'w'、'e'
	左中、中忠、右中	'a'、's'、'd'
	左下、中下、右下	'z'、'x'、'c'
	即鍵盤布局!
	*/
	CUI_CtnrCreate('q',VBOX);	//no def

	#ifdef _WIN32
	Sleep(1000);
	#endif

	/*
	預想的CUI使用過程：

	建立視窗
	建立容器
	於各容器放置各種元件
	*/

	CUI_Quit();
	return 0;
}