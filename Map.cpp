#include "Map.h"

Map::Map(){
	width = 22;
	height = 12;
}
Map::~Map(){
	if(map2dArray != NULL){
		delete map2dArray;
	}
}
bool Map::makeMap2dArray(){
	char** map2dArray = new char* [height];
	for(int i=0; i < height; i++){
		map2dArray[i] = new char [width];
	}
	this->map2dArray = map2dArray;
	return true;
}
void Map::build(){
	makeMap2dArray()
	srand(time(NULL));
	for (int y=0; y < height; ++y){
		for(int x=0; x < width; x++){
			
			if(x == 0 || x == width-1 || y == 0 || y == height-1){// create outside walls
				(map2dArray[y])[x] = Map::WALL;
			}else{////////////////////////////////////////////////// create inside of walls
				int random = rand() % 20;
				if(random > 9){
					(map2dArray[y])[x] = Map::WALL;
				}else{
					(map2dArray[y])[x] = Map::FREE;
				}
			}
			
		}
	}
	(map2dArray[1])[1] = Map::FREE; // this position belongs to Avatar so it should be empty
}
void Map::draw(){
	ConsoleController::goTo(0,0);
	for (int i=0; i < height; ++i){
		for(int j=0; j < width; j++){
			cout << (map2dArray[i])[j];
		}
		cout << endl;
	}
}
int Map::getMapWidth(){
	return width;
}
int Map::getMapHeight(){
	return height;
}
void Map::setMapDimens(const int WIDTH , const int HEIGHT){
	this->width = WIDTH + 2; //The + 2 is for outside walls
	this->height = HEIGHT + 2;
}
char** Map::getMap2dArray(){
	return map2dArray;
}
