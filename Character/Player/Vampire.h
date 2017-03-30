#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "Player.h"

class Vampire: public Player {
public:
	Vampire(int hp = 150, int atk = 25, int def = 15);
};

#endif