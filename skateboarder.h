#ifndef SBOARDER_H
#define SBOARDER_H

#include <QPixmap>
#include "thing.h"

class Skateboarder : public Thing {
	public:
		Skateboarder(QPixmap *pm, int nx, int ny);
		void move();
};

#endif // SBOARDER_CPP
