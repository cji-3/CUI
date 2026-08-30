#include <CUI.h>
#include <stdio.h>

void buttonClick(CUI_Cell *button){
	CUI_SetButtonText(button,"button yes!!!!!!!!!!!!!!!");
}

int main(){
	CUI_Init("CUI!",640,360);

	CUI_Box *box=CUI_CreateVBox(CUI_REFBOX_Q,0,CUI_BOXHWFLAG_MIN,NULL);
	CUI_Cell *button=CUI_CreateButton("button test!",buttonClick);
	CUI_BoxAddCell(box,button);

	CUI_Loop();

	CUI_Quit();
	return 0;
}