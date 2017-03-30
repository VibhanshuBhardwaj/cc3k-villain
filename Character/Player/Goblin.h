#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "Player.h"

class Goblin: public Player {
public:
	Goblin(int hp = 150, int atk = 25, int def = 15);
};

#endif