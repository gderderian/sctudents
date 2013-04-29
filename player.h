#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include "thing.h"

/** Player class, which represents a user controllable character. */
class Player : public Thing {
	public:
	Player(QPixmap *pm, int nx, int ny);
	void move();
	int getKey();
};

#endif // PLAYER_CPP
