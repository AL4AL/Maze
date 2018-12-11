#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED

#include<iostream>
#include <conio.h>
#include "ConsoleController.h"
#include "Direction.h"

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

using namespace std;

class Avatar {
	private:
		int xBorder;
		int yBorder;
		int x;
		int y;
		int previousX;
		int previousY;
	
		bool isKeyAllowed(const int KEY);
		
		void clearPreviousAvatar();
		
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		
		void isWallAt(Direction direction);
		
	public:
		static const char ANDICATOR = 'X';
		
		Avatar(int xBorder ,int yBorder);
		~Avatar();
		
		void getBack();
		void move(const int KEY);
		void draw();
};

#endif
