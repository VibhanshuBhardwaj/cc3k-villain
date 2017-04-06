#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "Enemy.h"

class Human: public Enemy {
public:
	Human(int atk = 20, int def = 20, int hp = 140);
	void onDeath(Player * p) override;
};

#endif
