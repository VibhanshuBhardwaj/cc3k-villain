#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "Enemy.h"

class Merchant: public Enemy {
	static bool areHostile;
public:
	bool isEnemyHostile();
	Merchant(int atk = 70, int def = 5, int hp = 30);
	void attackPlayer(Player * player) override;
	void makeHostile() override;
	void onDeath(Player * p) override;
};

#endif
