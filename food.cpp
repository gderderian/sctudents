#include "food.h"

using namespace std;

Food::Food(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny) {
}

void Food::move() {

	int velocityX = 0;
	int velocityY = -5;

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


int Food::getKey(){
	return 3;
}
