#include "grades.h"
#include <iostream>

using namespace std;

/** Constructor for grades, which makes a grades item at the given coordinates */
Grades::Grades(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny) {
}

/** Moves the grades items from left to right at a moderately fast pace within the game window. */
void Grades::move() {

	int velocityX = 5;
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
		@return 2, indicating this is a grades item, for action to be taken upon it during collisions in the MainWindow class.
*/
int Grades::getKey(){
	return 2;
}
