#include <CUI.h>
#include <string.h>
#include <stdio.h>

void buttonClick(CUI_Button *button){
	if(!strcmp(button->text,"bt1 哈")){
		button->text="bt1 幹";
		CUI_ButtonRenew(button);
	}
	else{
		button->text="button yes!!!!!!!!!!!!!";
		CUI_ButtonRenew(button);
	}
}

int main(){
	CUI_Init("CUI!",640,360);
	CUI_DebugShowBoxKnow();

	int asl[]={0,1,0};
	CUI_Box *box=CUI_CreateVBox(CUI_REFBOX_Q,0,CUI_BOXWHFLAG_MAX,asl);
	CUI_Button *button =CUI_CreateButton("button test!",buttonClick);
	CUI_Button *button1=CUI_CreateButton("bt1 哈",buttonClick);
	CUI_BoxAddCell(box,button);
	CUI_BoxAddCell(box,button1);

	CUI_Loop();

	CUI_Quit();
	return 0;
}