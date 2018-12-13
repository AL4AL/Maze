#ifndef CONSOLECONTROLLER_H_INCLUDED
#define CONSOLECONTROLLER_H_INCLUDED

#include <windows.h>
#include <conio.h>

class ConsoleController {
	private:
		
	public:
		void static goTo(int xPosition , int yPosition);
		void static clearScreen();
		void static setCursorVisibility(bool showFlag);
};

#endif
