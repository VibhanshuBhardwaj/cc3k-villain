#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "../Character.h"

#include "string"
#include "../Player/Player.h"
#include "vector"

class Enemy : public Character {
	bool isHostile;
	public:
		virtual void attackPlayer(Player *);
		Enemy(int atk, int def, int hp, char symbol, bool isHostile);
		//bool isPlayerNearby();
		std::string getRace();
		virtual bool isEnemyHostile();
		virtual ~Enemy();
};
#endif