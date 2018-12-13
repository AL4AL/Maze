#include "Game.h"

Game::Game(Map *map, Avatar* avatar){
	this->map = map;
	this->avatar = avatar;
}
Game::~Game(){
}
void Game::listenToInputKey(){
	while (true){
		while(kbhit() > 0){
			int pressedKey = getch();
			if(pressedKey == 224)
				continue;
			//after here pressedKey is usable
			map->draw();
			avatar->move(pressedKey);
			avatar->draw();
		}
	}
}
void Game::showGuide(){
	ConsoleController::goTo(map->getMapWidth() + 3,  0);
	cout << "Move your avatar by Keys: W A S D , or by Arrow keys";
	ConsoleController::goTo(map->getMapWidth() + 3,  1);
	cout << Map::WALL << " is wall, you cant get pass them";
	ConsoleController::goTo(map->getMapWidth() + 3,  2);
	cout << Map::BOMB << " is bomb, if you go on them, you will lose";
	ConsoleController::goTo(map->getMapWidth() + 3,  3);
	cout << Map::TARGET << " is target, you should go there to win";
	
}
void Game::start(){
	map->build();
	map->draw();
	avatar->setMap(map->getMap2dArray());
	ConsoleController::goTo(1,1);
	cout << Avatar::ANDICATOR;
	ConsoleController::setCursorVisibility(false);
	listenToInputKey();
}
