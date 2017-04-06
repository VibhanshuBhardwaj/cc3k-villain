#include "Dragon.h"

Dragon::Dragon(int atk, int def, int hp, Item *dh): Enemy(atk, def, hp, 'D', true), hoard{dh}{
}

void Dragon::onDeath(Player * p) {
	this->getCurrCell()->leave();
	hoard->setAvailable();
	hoard->getCurrCell()->dragonHoard = false;

}
