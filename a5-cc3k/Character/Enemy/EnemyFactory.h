#ifndef _ENEMYFACTORY_H
#define _ENEMYFACTORY_H
#include "Enemy.h"

class EnemyFactory {
public:
	Enemy * generateEnemy();
	Enemy * generateEnemy(char e);
};

#endif
