#include <CUI.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(){
	CUI_Init("CUI!",640,360);
	printf("CUI_Init(\"CUI\",640,360);\n");

	CUI_Box *box=CUI_CreateVBox(CUI_REFBOX_Q,0,CUI_BOXHWFLAG_AUTO,CUI_BOXHWFLAG_AUTO);
	CUI_Cell *button=CUI_CreateButton("button");
	CUI_BoxAddCell(box,button);

	CUI_Loop();

	CUI_Quit();
	return 0;
}