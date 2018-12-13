#include "ConsoleController.h"

void ConsoleController::goTo (int xPosition , int yPosition){
	static HANDLE h = NULL;
	if (!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {xPosition, yPosition};
	SetConsoleCursorPosition(h, c);
}


void ConsoleController::clearScreen(){
	system("cls");
}
void ConsoleController::setCursorVisibility(bool showFlag){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
