#include <CUI.h>
#include <string.h>
#include <stdio.h>

void buttonClick(CUI_Button *button){
	if(!strcmp(button->text,"bt1 哈")){
		button->text="bt1 幹";
		CUI_RenewCell(CUI_CELL(button));
	}
	else if(!strcmp(button->text,"2u2u is gay")){
		button->text="yes!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		CUI_RenewCell(CUI_CELL(button));
	}
	else{
		button->text="button yes!!!!!!!!!!!!!";
		CUI_RenewCell(CUI_CELL(button));
	}
}

int main(){
	CUI_Init("CUI!",640,360);
	CUI_DebugShowBoxKnow(true);

	CUI_Box *box=CUI_NewVBox(CUI_REFBOX_TOPLEFT,0,CUI_BOXWHFLAG_WIN,(int[]){0,1,1,0},CUI_BOXWHFLAG_MIN,NULL);
	CUI_NewButton(box,"VBox test",buttonClick);
	CUI_NewButton(box,"button1 0 is index no.1",buttonClick);
	CUI_NewButton(box,"2u2u is gay",buttonClick);

	CUI_Box *box1=CUI_NewVBox(box,CUI_BOXVH_H,CUI_BOXWHFLAG_MAX,(int[]){0,1,0},CUI_BOXWHFLAG_MIN,NULL);
	CUI_NewButton(box1,"VBox test",buttonClick);
	CUI_NewButton(box1,"button1 0 is index no.1",buttonClick);

	CUI_Box *box2=CUI_NewVBox(box1,CUI_BOXVH_V,100,(int[]){0,1,0},CUI_BOXWHFLAG_MIN,NULL);
	CUI_NewButton(box2,"VBox test",buttonClick);
	CUI_NewButton(box2,"button1 0 is index no.1",buttonClick);

	CUI_Loop();

	CUI_Quit();
	return 0;
}