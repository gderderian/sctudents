#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include "thing.h"

class Player : public Thing {
	public:
	Player(QPixmap *pm, int nx, int ny);
	void move();
};

#endif // PLAYER_CPP