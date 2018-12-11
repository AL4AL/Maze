#include "Avatar.h"
#include "Map.h"
Avatar::Avatar(int xBorder ,int yBorder){
	x = 0;
	y = 0;
	this->xBorder = xBorder;
	this->yBorder = yBorder;
}
Avatar::~Avatar(){
}
void Avatar::move(const int KEY){
	if(isKeyAllowed(KEY)){
		previousX = x;
		previousY = y;
		switch(KEY){
			case UP:
			case UP_ARROW: moveUp();
				break;
			case DOWN:
			case DOWN_ARROW: moveDown();
				break;
			case LEFT:
			case LEFT_ARROW: moveLeft();
				break;
			case RIGHT:
			case RIGHT_ARROW: moveRight();
				break;
		}
	}
}
void Avatar::clearPreviousAvatar(){
	goTo(x , y);
	cout << Map::FREE;
}
void Avatar::moveUp(){
	if(y != 0)
		--y;		
}
void Avatar::moveDown(){
	bool condit = yBorder-1 != y;
	if(condit)
		++y;
}
void Avatar::moveLeft(){
	if(x != 0)
		--x;
}
void Avatar::moveRight(){
	if(xBorder-1 != x)
		++x;
}
void Avatar::goTo (int xPosition , int yPosition){
	static HANDLE h = NULL;
	if (!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {xPosition, yPosition};
	SetConsoleCursorPosition(h, c);
}
bool Avatar::isKeyAllowed(const int KEY){
	switch(KEY){
		case UP:
		case UP_ARROW:
		case DOWN:
		case DOWN_ARROW:
		case LEFT:
		case LEFT_ARROW:
		case RIGHT:
		case RIGHT_ARROW:
			return true;
			break;
		default: return false;
			break;
	}
}
void Avatar::draw(){
	Avatar::goTo(x, y);
	cout << Avatar::ANDICATOR;
}
void Avatar::getBack(){
	x = previousX;
	y = previousY;
}
