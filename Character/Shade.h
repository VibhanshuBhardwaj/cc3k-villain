#ifndef _SHADE_H_
#define _SHADE_H_

#include "Player.h"

class Shade: public Player {
public:
	Shade(int hp = 120, int atk = 20, int def = 25);
};

#endif