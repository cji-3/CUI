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

	CUI_Quit();
	return 0;
}