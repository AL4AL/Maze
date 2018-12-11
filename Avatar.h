#include<iostream>
#include <conio.h>
#include <windows.h>

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
		
	public:
		static const char ANDICATOR = 'X';
		
		Avatar(int xBorder ,int yBorder);
		~Avatar();
		
		void getBack();
		void move(const int KEY);
		
		void static goTo(int xPosition , int yPosition);
		
		void draw();
};
