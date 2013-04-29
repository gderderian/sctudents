#include "player.h"

using namespace std;

/** Constructor for player, which makes a player at the given coordinates */
Player::Player(QPixmap *pm,int nx,int ny) : Thing(pm,nx,ny) {
}

/** Player is automatically moved in MainWindow() through setX() and setY() parent functions */
void Player::move(){
}

/** Gets the unique key of this derived object. 
		@return -1, indicating this is a player, for action to be taken upon it during collisions in the MainWindow class.
*/
int Player::getKey(){
	return -1;
}
