#ifndef FOOD_H
#define FOOD_H

#include <QPixmap>
#include "thing.h"

class Food : public Thing {
	public:
		Food(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // FOOD_CPP
