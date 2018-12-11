#include "Avatar.h"
#include "Map.h"
#include <conio.h>
#include <windows.h>
#include <iostream>


using namespace std;

class Game {
	private:
		Avatar *avatar;
		Map *map;
		void listenToInputKey();
		void clearScreen();
		
	public:
		Game(Map* map, Avatar* avatar);
		~Game();
		void start();
};
