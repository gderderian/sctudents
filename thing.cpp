#ifndef THING_CPP
#define THING_CPP

#include "thing.h"

using namespace std;

Thing::Thing(QPixmap* p, int nx, int ny) {
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	setPos(x,y);
}

int Thing::getX(){
	return x;
}

int Thing::getY(){
	return y;
}

void Thing::setX(int new_x){
	x = new_x;
	setPos(new_x,y);
}

void Thing::setY(int new_y){
	y = new_y;
	setPos(x,new_y);
}

void Thing::setvX(int new_vx){
	vX = new_vx;;
}

void Thing::setvY(int new_vy){
	vY = new_vy;
}

int Thing::getvX(){
	return vX;
}

int Thing::getvY(){
	return vY;
}

#endif // THING_CPP
