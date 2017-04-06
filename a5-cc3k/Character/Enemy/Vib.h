#ifndef _VIB_H_
#define _VIB_H_

#include "Enemy.h"

class Vib: public Enemy {
public:
	Vib(int atk = 80, int def = 50, int hp = 200);
	void onDeath(Player *);
};

#endif
