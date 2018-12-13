#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include "ConsoleController.h"

using namespace std;

class Map {
	private:
		int count;
		int width;
		int height;
		int targetX;
		int targetY;
		char** map2dArray; //initialize in build()
		
		bool makeMap2dArray();
		void openWay(int startXPositin , int startYPosition);
	public:
		Map();
		~Map();
		void setMapDimens(const int WIDTH , const int HEIGHT);
		int getMapWidth();
		int getMapHeight();
		int setMapHeight();
		void build();
		void draw();
		char** getMap2dArray();
		static const char WALL = char(219);
		static const char BOMB = 'B';
		static const char FREE = ' ';
		static const char TARGET = 'X';
};

#endif
