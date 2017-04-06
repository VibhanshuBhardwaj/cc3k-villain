#ifndef _TROLL_H_
#define _TROLL_H_

#include "Player.h"

class Troll: public Player {
public:
	Troll(int hp = 120, int atk = 25, int def = 15);
};

#endif

