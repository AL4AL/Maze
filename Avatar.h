#ifndef AVATAR_H_INCLUDED
#define AVATAR_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdexcept>
#include "ConsoleController.h"
#include "Direction.h"
#include "Map.h"

#define UP_W 119
#define DOWN_S 115
#define LEFT_A 97
#define RIGHT_D 100

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
		char** map2dArray;
	
		bool isKeyAllowed(const int KEY);
		
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void winCheck();
		bool isWallAt(Direction direction);
		
	public:
		static const char ANDICATOR = 'X';
		
		Avatar(int xBorder ,int yBorder);
		~Avatar();
		
		void getBack();
		void move(const int KEY);
		void draw();
		void setMap(char** map2dArray);
};

#endif
