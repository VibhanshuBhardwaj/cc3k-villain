#include "Enemy.h"

using namespace std;

//Enemy::Enemy() {}

Enemy::Enemy(int atk, int def, int hp, char symbol, bool isHostile): Character(atk, def, hp, symbol), isHostile(isHostile) {}

bool Enemy::isEnemyHostile() { return isHostile; }


void Enemy::attackPlayer(Player* player) {

	if (!player) {}//cout << "No enemy to attack at that position!" << endl;
	else {
		int damageDealt = ceil((100/(100 + float(player->getDef())))* float(this->getAtk()));
		string newAction = player->getAction() + "Damage done by " + this->getSymbol() + " to " + player->getSymbol() + ": " +  to_string(damageDealt) + "HP. ";
		player->setAction(newAction);
		//cout << "old player hp" << player->getHp() << endl;
		player->setHp(player->getHp() - damageDealt );
		//cout << "new player hp" << player->getHp() << endl;

	}

}
string Enemy::getRace() {
	return "Enemy";
}
void Enemy::makeHostile() {}

void Enemy::onDeath(Player* player) {
	getCurrCell()->leave();
	int i  = rand() % 2;
	if (i) player->setScore(player->getScore() + 1);
	else player->setScore(player->getScore() + 2);
}
Enemy::~Enemy() {}