#include "food.h"

using namespace std;

/** Constructor for food, which makes a item of food at the given coordinates */
Food::Food(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny) {
}

/** Moves food up from the bottom of the screen at a relatively fast rate */
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

/** Gets the unique key of this derived object. 
		@return 3, indicating this is a food item, for action to be taken upon it during collisions in the MainWindow class.
*/
int Food::getKey(){
	return 3;
}
