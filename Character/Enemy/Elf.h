#ifndef _ELF_H_
#define _ELF_H_

#include "Enemy.h"

class Elf: public Enemy {
public:
	Elf(int atk = 30, int def = 10, int hp = 140);
};

#endif