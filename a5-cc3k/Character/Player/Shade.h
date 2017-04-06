#ifndef _SHADE_H_
#define _SHADE_H_

#include "Player.h"

class Shade: public Player {
	//void attack(Character *victim) override;
public:
	Shade(int hp = 125, int atk = 25, int def = 25);
};

#endif

