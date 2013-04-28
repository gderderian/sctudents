#ifndef GRADES_H
#define GRADES_H

#include <QPixmap>
#include "thing.h"

class Grades : public Thing {
	public:
		Grades(QPixmap *pm, int nx, int ny);
		void move();
		int getKey();
};

#endif // GRADE_CPP
