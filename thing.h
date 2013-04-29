#ifndef THING_H
#define THING_H

#include <QPixmap>
#include <QGraphicsPixmapItem>

using namespace std;

/** Thing class which other classes derive from to create onscreen objects that can be moved around in gameplay. */
class Thing : public QGraphicsPixmapItem {
	public:
		Thing(QPixmap *pm, int nx, int ny);
		/** Virtual object move function, implemented by derived classes */
		virtual void move() = 0;
		/** Virtual getkey function, implemented by derived classes to return the type of item in order to act on collisions appropraitely in MainWindow*/
		virtual int getKey() = 0;
		int getX();
		int getY();
		void setX(int new_x);
		void setY(int new_y);
		int getvX();
		int getvY();
		void setvX(int new_vX);
		void setvY(int new_vY);
	private:
		/** X-value of the current thing */
		int x;
		/** Y-value of the current thing */
		int y;
		/** X-velocity of the current thing */
		int vX;
		/** Y-value of the current thing */
		int vY;
		/** Pixmap associated with the current thing */
		QPixmap *pixMap;
};

#endif // THING_H
