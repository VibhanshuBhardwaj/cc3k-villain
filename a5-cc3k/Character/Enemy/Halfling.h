#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "Enemy.h"

class Halfling: public Enemy {
public:
	Halfling(int atk = 15, int def = 20, int hp = 100);
};

#endif
