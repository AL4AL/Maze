#include <iostream>
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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class X {
	private:
		
		int x;
		int y;
	
		bool isKeyAllowed(const int KEY);
		
		void goToXY (int x , int y);
		void clearPreviousX();
		
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		
		
	public:
		X();
		void move(const int KEY);
};
X::X(){
	x = 0;
	y = 0;
}

void clearScreen();

int main(int argc, char** argv) {
	cout << "X";
	X *x = new X();
	while (true){
		while(kbhit() > 0){
			int pressedKey = getch();
			if(pressedKey == 224)
				continue;	
			x->move(pressedKey);
		}
	}
	delete x;
	return 1;
}

void X::move(const int KEY){
	if(isKeyAllowed(KEY)){
		clearPreviousX();
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

void X::clearPreviousX(){
	goToXY(x , y);
	cout <<" ";
}
void X::moveUp(){
	if(y == 0)
		return;
		
	goToXY(x , --y);
	cout << "X";
}
void X::moveDown(){
	
	goToXY(x , ++y);
	cout << "X";
	
}
void X::moveLeft(){
	if(x == 0)
		return;
		
	goToXY(--x , y);
	cout << "X";
}
void X::moveRight(){
	goToXY(++x , y);
	cout << "X";
}

void X::goToXY (int x , int y){
	static HANDLE h = NULL;
	if (!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}

bool X::isKeyAllowed(const int KEY){
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
void clearScreen(){
	system("cls");
}
