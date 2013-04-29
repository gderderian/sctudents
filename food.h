#ifndef FOOD_H
#define FOOD_H

#include <QPixmap>
#include "thing.h"

/** Food (dining hall food) class, which represents an item that can hurt the user. */
class Food : public Thing {
	public:
		Food(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // FOOD_CPP
