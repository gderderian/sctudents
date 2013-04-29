#ifndef COFFEE_H
#define COFFEE_H

#include <QPixmap>
#include "thing.h"

/** Coffee class, which represents a moving coffee that gives the user another life. */
class Coffee : public Thing {
	public:
		Coffee(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // COFFEE_CPP
