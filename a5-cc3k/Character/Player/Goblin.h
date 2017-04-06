#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "Player.h"

class Goblin: public Player {
public:
	Goblin(int hp = 110, int atk = 15, int def = 20);
};

#endif

