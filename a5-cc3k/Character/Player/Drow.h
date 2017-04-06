#ifndef _DROW_H_
#define _DROW_H_

#include "Player.h"

class Drow: public Player {
public:
	Drow(int hp = 150, int atk = 25, int def = 15);
};

#endif
