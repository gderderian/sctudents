#include "coffee.h"

using namespace std;

Coffee::Coffee(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

void Coffee::move() {

	int velocityX = -8;
	int velocityY = 0;

	int x_ = getX();
	int y_ = getY();

	int newX = x_ += velocityX;
	int newY = y_ += velocityY;

	if (newX >= 625 || newX <= 0){
		hide();
	} else {
		setX(newX);
	}
 
 	if (newY >= 400 || newY <= 0){
 		hide();
 	} else {
 		setY(newY);
 	}

}

int Coffee::getKey(){
	return 4;
}
