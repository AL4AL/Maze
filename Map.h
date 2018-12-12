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
		int width;
		int height;
		char** map2dArray; //initialize in build()
		bool makeMap2dArray();
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
		static const char WALL = '#';
		static const char FREE = ' ';
};

#endif
