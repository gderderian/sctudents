#ifndef THING_H
#define THING_H

#include <QPixmap>
 #include <QGraphicsPixmapItem>

using namespace std;

class Thing : public QGraphicsPixmapItem {
	public:
		Thing(QPixmap *pm, int nx, int ny);
		virtual void move() = 0;
		int getX();
		int getY();
		void setX(int new_x);
		void setY(int new_y);
		int getvX();
		int getvY();
		void setvX(int new_vX);
		void setvY(int new_vY);
	private:
		int x;
		int y;
		int vX;
		int vY;
		QPixmap *pixMap;
};

#endif // THING_H
