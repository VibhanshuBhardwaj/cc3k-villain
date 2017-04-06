#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "Player.h"

class Vampire: public Player {
public:
	Vampire(int hp = 50, int atk = 25, int def = 25);
	void onAttack(char symbol);
	void attack(Character * victim);
};

#endif

