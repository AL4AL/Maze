#ifndef CONSOLECONTROLLER_H_INCLUDED
#define CONSOLECONTROLLER_H_INCLUDED

#include <windows.h>

class ConsoleController {
	private:
		
	public:
		void static goTo(int xPosition , int yPosition);
		void clearScreen();
};

#endif
