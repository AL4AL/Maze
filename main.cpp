#include "Game.h"
#define WIDTH 20
#define HEIGHT 10

//  CAUTION: THIS PROJECT USES C++11
int main(int argc, char** argv) {
	Map *map = new Map();
	map->setMapDimens(WIDTH,HEIGHT);
	Avatar* avatar = new Avatar(map->getMapWidth() , map->getMapHeight());
	Game *game = new Game(map,avatar);
	
	game->start();
	
	delete game;
	delete map;
	delete avatar;
	
	return 1;
}

