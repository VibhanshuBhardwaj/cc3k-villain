#include <string>
#include "Merchant.h"

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

