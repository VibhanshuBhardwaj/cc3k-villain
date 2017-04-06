#ifndef _ORC_H_
#define _ORC_H_

#include "Enemy.h"

class Orc: public Enemy {
public:
	void attackPlayer(Player *) override;
	Orc(int atk = 30, int def = 25, int hp = 180);
};

#endif
