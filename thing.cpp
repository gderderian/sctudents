#ifndef THING_CPP
#define THING_CPP

#include "thing.h"

using namespace std;

/** Constructor for thing which builds a thing at the given location with the given velocity
		@param p Pixmap representing the curren thing.
		@param nx X-value for the current thing.
		@param ny Y-value for the curren thing.
*/
Thing::Thing(QPixmap* p, int nx, int ny) {
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	setPos(x,y);
}

/** Getter for the X-value of the current thing
		@return X-value of the current thing.
*/
int Thing::getX(){
	return x;
}

/** Getter for the Y-value of the current thing
		@return Y-value of the current thing.
*/
int Thing::getY(){
	return y;
}

/** Setter for the X-value of the current thing
		@param new_x The new x-value of the thing.
*/
void Thing::setX(int new_x){
	x = new_x;
	setPos(new_x,y);
}

/** Setter for the Y-value of the current thing
		@param new_y The new y-value of the thing.
*/
void Thing::setY(int new_y){
	y = new_y;
	setPos(x,new_y);
}

/** Setter for the X-velocity of the current thing
		@param new_vx The new x-velocity of the thing.
*/
void Thing::setvX(int new_vx){
	vX = new_vx;;
}

/** Setter for the Y-velocity of the current thing
		@param new_vy The new y-velocity of the thing.
*/
void Thing::setvY(int new_vy){
	vY = new_vy;
}

/** Getter for the X-velocity of the current thing
		@return X-velocity of the current thing.
*/
int Thing::getvX(){
	return vX;
}

/** Getter for the Y-velocity of the current thing
		@return Y-velocity of the current thing.
*/
int Thing::getvY(){
	return vY;
}

#endif // THING_CPP
