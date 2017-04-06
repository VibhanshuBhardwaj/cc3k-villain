#ifndef _DWARF_H_
#define _DWARF_H_

#include "Enemy.h"

class Dwarf: public Enemy {
public:
	Dwarf(int atk = 20, int def = 30, int hp = 100);
};

#endif
