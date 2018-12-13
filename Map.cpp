#include "Map.h"

Map::Map(){
	width = 22;
	height = 12;
	targetX = width -1;
	targetY = height -1;
	count = 0;
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
	makeMap2dArray();
	srand(time(NULL));
	for (int y=0; y < height; ++y){
		for(int x=0; x < width; x++){
			
			if(x == 0 || x == width-1 || y == 0 || y == height-1){// create outside walls
				(map2dArray[y])[x] = Map::WALL;
			}else{////////////////////////////////////////////////// create inside of walls
				int random = rand() % 20;
				if(random > 10){
					(map2dArray[y])[x] = Map::WALL;
				}else{
					(map2dArray[y])[x] = Map::FREE;
				}
				if (random > 18)
					(map2dArray[y])[x] = Map::BOMB;
			}
			
		}
	}
	(map2dArray[1])[1] = Map::FREE; // this position belongs to Avatar so it should be empty
	(map2dArray[targetY])[targetX] = Map::TARGET; // this position belongs to Target so it should be Target
	openWay(1,1);
}
void Map::openWay(int startXPosition , int startYPosition){ // checks if way to target is closed, opens it
	if(startXPosition == targetX-1 && startYPosition == targetY){ //current position is right before target on the left side
		return;
	}
	if(startXPosition == targetX && startYPosition == targetY-1){ //current position is right before target on the top side
		return;
	}
	if((map2dArray[startYPosition+1])[startXPosition] == Map::FREE){ // way to down is open
		openWay(startXPosition, startYPosition + 1); /////////// Moves down
		return;
	}
	if((map2dArray[startYPosition])[startXPosition+1] == Map::FREE){ // way to right is open
		openWay(startXPosition+1, startYPosition);// moves right
		return;
	}
	if(startXPosition == targetX && startYPosition < targetY){ // if is on the last right side column and on top of target
		(map2dArray[startYPosition+1])[startXPosition] = Map::FREE; // open down
		openWay(startXPosition, startYPosition+1);
		return;
	}
	(map2dArray[startYPosition])[startXPosition+1] = Map::FREE; // open right
		openWay(startXPosition + 1, startYPosition);// moves right
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
	targetX = WIDTH;
	targetY = HEIGHT;
}
char** Map::getMap2dArray(){
	return map2dArray;
}
