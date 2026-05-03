#include<stdbool.h>
#include<windows.h>

#include "../include/CUI.h"

int main(int argc,char* argv[]) {
	CUI_Init("test",50,50,640,360,CUI_INIT_WINDOW_MODE_SHOWN);

    Sleep(1000);

	CUI_Quit();
	return 0;
}