#include "skateboarder.h"

using namespace std;

/** Constructor for skateboarder, which makes a skateboarder at the given coordinates */
Skateboarder::Skateboarder(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

/** Moves the skateboarder within the screen from left, curving up to the right, with a polynomial line/slope formula based on the set velocity of the object.
*/
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

/** Gets the unique key of this derived object. 
		@return 1, indicating this is a skatebaorder, for action to be taken upon it during collisions in the MainWindow class.
*/
int Skateboarder::getKey(){
	return 1;
}
