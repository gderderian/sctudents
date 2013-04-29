#include "skateboarder.h"

using namespace std;

Skateboarder::Skateboarder(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

void Skateboarder::move() {

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
 		int set = (300 - (0.00075)*(((newX - 400) - 135)*((newX - 400) - 135)) - 50);
 		setY(set);
 	}

}

int Skateboarder::getKey(){
	return 1;
}
