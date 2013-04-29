#ifndef ECREDIT_H
#define ECREDIT_H

#include <QPixmap>
#include "thing.h"

/** Extra credit class, which represents a piece of extra credit the user can gain points from. */
class ExtraCredit : public Thing {
	public:
		ExtraCredit(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // ECREDIT_CPP
