#include "coffee.h"

using namespace std;

/** Constructor for coffee, which makes a new coffee item at the given coordinates */
Coffee::Coffee(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

/** Moves the coffee from left to right at a fast pace within the gamewindow */
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

/** Gets the unique key of this derived object. 
		@return 4, indicating this is a Trojan Grounds Coffee, for action to be taken upon it during collisions in the MainWindow class.
*/
int Coffee::getKey(){
	return 4;
}
