#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ConsoleController.h"

using namespace std;

class Map {
	private:
		int width;
		int height;
		char** rows; //every row points to rows that contain columns as much as width
	public:
		Map();
		~Map();
		void setMapDimens(const int WIDTH , const int HEIGHT);
		int getMapWidth();
		int getMapHeight();
		int setMapHeight();
		void build();
		void draw();
		static const char WALL = '#';
		static const char FREE = ' ';
};

#endif
