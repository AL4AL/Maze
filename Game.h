#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Avatar.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "Map.h"

using namespace std;

class Game {
	private:
		Avatar *avatar;
		Map *map;
		void listenToInputKey();
		
	public:
		Game(Map* map, Avatar* avatar);
		~Game();
		void start();
};

#endif
