#include "extracredit.h"

using namespace std;

/** Constructor for extra credit, which makes a new extra credit item at the given coordinates */
ExtraCredit::ExtraCredit(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

/** Moves the extra credit from left to right at a fast pace within the game window. */
void ExtraCredit::move() {

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
		@return 5, indicating this is a piece of extra credit, for action to be taken upon it during collisions in the MainWindow class (add points).
*/
int ExtraCredit::getKey(){
	return 5;
}
