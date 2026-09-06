#include <CUI.h>
#include <string.h>
#include <stdio.h>

void buttonClick(CUI_Button *button){
	if(!strcmp(button->text,"bt1 哈")){
		button->text="bt1 幹";
		CUI_RenewCell(button);
	}
	else if(!strcmp(button->text,"2u2u is gay")){
		button->text="yes!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		CUI_RenewCell(button);
	}
	else{
		button->text="button yes!!!!!!!!!!!!!";
		CUI_RenewCell(button);
	}
}

int main(){
	CUI_Init("CUI!",640,360);
	CUI_DebugShowBoxKnow();

	CUI_Box *box=CUI_NewVBox(CUI_REFBOX_Q,0,CUI_BOXWHFLAG_WIN,(int[]){0,1,0});
	CUI_Button *button=CUI_NewButton("VBox test",buttonClick);
	CUI_Button *button1=CUI_NewButton("button1 0 is index no.1",buttonClick);
	CUI_BoxAddCell(box,button);
	CUI_BoxAddCell(box,button1);

	CUI_Loop();

	CUI_Quit();
	return 0;
}