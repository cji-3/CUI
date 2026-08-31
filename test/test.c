#include <CUI.h>
#include <string.h>
#include <stdio.h>

void buttonClick(CUI_Button *button){
	if(!strcmp(button->text,"bt1 哈")){
		CUI_SetButtonText(button,"bt1 幹");
	}
	else if(!strcmp(button->text,"bt2 哈")){

	}
	else{
		CUI_SetButtonText(button,"button yes!!!!!!!!!!!!!!!");
	}
}

int main(){
	CUI_Init("CUI!",640,360);

	CUI_Box *box=CUI_CreateVBox(CUI_REFBOX_Q,0,CUI_BOXHWFLAG_MIN,(int*){0,1,0});
	CUI_Button *button=CUI_CreateButton("button test!",buttonClick);
	CUI_Button *button1=CUI_CreateButton("bt1 哈",buttonClick);
	CUI_Button *button2=CUI_CreateButton("bt2 哈",buttonClick);
	CUI_BoxAddCell(box,button);
	CUI_BoxAddCell(box,button1);
	CUI_BoxAddCell(box,button2);

	CUI_Loop();

	CUI_Quit();
	return 0;
}