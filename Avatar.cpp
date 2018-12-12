#include "Avatar.h"
#include "Map.h"

Avatar::Avatar(int xBorder ,int yBorder){
	x = 1;
	y = 1;
	this->xBorder = xBorder;
	this->yBorder = yBorder;
	map2dArray = NULL;
}
Avatar::~Avatar(){
}
void Avatar::move(const int KEY){
	if(isKeyAllowed(KEY)){
		previousX = x;
		previousY = y;
		switch(KEY){
			case UP_W:
			case UP_ARROW: moveUp();
				break;
			case DOWN_S:
			case DOWN_ARROW: moveDown();
				break;
			case LEFT_A:
			case LEFT_ARROW: moveLeft();
				break;
			case RIGHT_D:
			case RIGHT_ARROW: moveRight();
				break;
		}
	}
}
/*
void Avatar::clearPreviousAvatar(){
	ConsoleController::goTo(x , y);
	cout << Map::FREE;
}
*/
void Avatar::moveUp(){
	if(y != 0)
		if(!isWallAt(Direction::TOP))
			--y;		
}
void Avatar::moveDown(){
	bool condit = yBorder-1 != y;
	if(condit)
		if(!isWallAt(Direction::BOTTOM))
			++y;
}
void Avatar::moveLeft(){
	if(x != 0)
		if(!isWallAt(Direction::LEFT))
			--x;
}
void Avatar::moveRight(){
	if(xBorder-1 != x)
		if(!isWallAt(Direction::RIGHT))
			++x;
}
bool Avatar::isKeyAllowed(const int KEY){
	switch(KEY){
		case UP_W:
		case UP_ARROW:
		case DOWN_S:
		case DOWN_ARROW:
		case LEFT_A:
		case LEFT_ARROW:
		case RIGHT_D:
		case RIGHT_ARROW:
			return true;
			break;
		default: return false;
			break;
	}
}
void Avatar::draw(){
	ConsoleController::goTo(x, y);
	cout << Avatar::ANDICATOR;
}
void Avatar::setMap(char** map2dArray){
	this->map2dArray = map2dArray;
}
void Avatar::getBack(){
	x = previousX;
	y = previousY;
}
bool Avatar::isWallAt(Direction direction){
	if(map2dArray != NULL){
		switch (direction){
			case Direction::TOP :{
				if ((map2dArray[y-1])[x] == Map::WALL)
					return true;
				else
					return false;
			}
			case Direction::BOTTOM :{
				if ((map2dArray[y+1])[x] == Map::WALL)
					return true;
				else
					return false;
			}
			case Direction::LEFT :{
				if ((map2dArray[y])[x-1] == Map::WALL)
					return true;
				else
					return false;
			}
			case Direction::RIGHT :{
				if ((map2dArray[y])[x+1] == Map::WALL)
					return true;
				else
					return false;
			}
			default: return false;
		}
	}else{
		throw logic_error("didn't set map for avatar, use setMap()");
	}
}

