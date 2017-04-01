#include "Enemy.h"
#include <iostream>


using namespace std;

//Enemy::Enemy() {}

Enemy::Enemy(int atk, int def, int hp, char symbol, bool isHostile): Character(atk, def, hp, symbol), isHostile(isHostile) {}

bool Enemy::isEnemyHostile() { return isHostile; }
void Enemy::attackPlayer(Character* player) {

	if (!player) {}//cout << "No enemy to attack at that position!" << endl;
	else {
		float damageDealt = (100/(100 + float(player->getDef())))* float(this->getAtk());
		cout << this->getSymbol() << " attacked " << player->getSymbol() << endl;
		//cout << "old player hp" << player->getHp() << endl;
		player->setHp(player->getHp() - damageDealt );
		//cout << "new player hp" << player->getHp() << endl;

	}

}
Enemy::~Enemy() {}