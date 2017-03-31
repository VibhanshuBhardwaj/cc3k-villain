#include "Enemy.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Enemy::Enemy() {}

Enemy::Enemy(int atk, int def, int hp, char symbol, bool isHostile): Character(atk, def, hp, symbol), isHostile(isHostile) {}

bool Enemy::isEnemyHostile() { return isHostile; }
void Enemy::attackPlayer(Character* player) { cout << this->getSymbol() << " attacked " << player->getSymbol() << endl;}
Enemy::~Enemy() {}