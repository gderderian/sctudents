#ifndef GRADES_H
#define GRADES_H

#include <QPixmap>
#include "thing.h"

/** Grades class, which represents a grades item the user can catch to earn points. */
class Grades : public Thing {
	public:
		Grades(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // GRADE_CPP
