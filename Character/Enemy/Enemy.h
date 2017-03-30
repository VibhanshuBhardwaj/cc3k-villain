#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "../Character.h"
#include "string"
#include "vector"

class Enemy : public Character {
	bool isHostile;
	public:
		Enemy(int atk, int def, int hp, char symbol, bool isHostile);
		virtual bool isEnemyHostile();
		virtual ~Enemy();
};
#endif