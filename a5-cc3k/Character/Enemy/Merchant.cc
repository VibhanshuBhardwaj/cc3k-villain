#include <string>
#include "Merchant.h"
#include "../../Item/Gold/Gold.h"

using namespace std;
bool Merchant::areHostile = false;

Merchant::Merchant(int atk, int def, int hp): Enemy(atk, def, hp, 'M', false) {}


void Merchant::makeHostile() {
	areHostile = true;
}

bool Merchant::isEnemyHostile() {
	return areHostile;
}

void Merchant::attackPlayer(Player * player) {
	if (!areHostile) return;
	else {
		Enemy::attackPlayer(player);
	}
}

void Merchant::onDeath(Player * p) {

	this->getCurrCell()->leave();
	Gold * g = new merchantHoard();
	getCurrCell()->occupy(g);
}
