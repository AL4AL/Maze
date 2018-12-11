#include "Map.h"

Map::Map(){
	width = 20;
	height = 10;
}
Map::~Map(){
	if(rows != NULL){
		delete rows;
	}
}
void Map::build(){
	char** rows = new char* [height];
	for(int i=0; i < height; i++){
		rows[i] = new char [width];
	}
	srand(time(NULL));
	for (int i=0; i < height; ++i){
		for(int j=0; j < width; j++){
			int random = rand() % 20;
			if(random > 9){
				(rows[i])[j] = Map::WALL;
			}else{
				(rows[i])[j] = Map::FREE;
			}
		}
	}
	this->rows = rows;
}
void Map::draw(){
	for (int i=0; i < height; ++i){
		for(int j=0; j < width; j++){
			cout << (rows[i])[j];
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
	this->width = WIDTH;
	this->height = HEIGHT;
}
