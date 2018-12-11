#include "Game.h"
#define WIDTH 20
#define HEIGHT 10

int main(int argc, char** argv) {
	Map *map = new Map();
	map->setMapDimens(8,4);
	Avatar* avatar = new Avatar(map->getMapWidth() , map->getMapHeight());
	Game *game = new Game(map,avatar);
	
	game->start();
	
	delete game;
	delete map;
	delete avatar;
	
	return 1;
}
