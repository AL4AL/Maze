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
			Avatar::goTo(0,0);
			map->draw();
			avatar->move(pressedKey);
			avatar->draw();
		}
	}
}
void Game::start(){
	map->build();
	map->draw();
	Avatar::goTo(0,0);
	cout << Avatar::ANDICATOR;
	listenToInputKey();
}
void Game::clearScreen(){
	system("cls");
}
