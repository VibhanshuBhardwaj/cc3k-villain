#include "Enemy.h"

using namespace std;

//Enemy::Enemy() {}

Enemy::Enemy(int atk, int def, int hp, char symbol, bool isHostile): Character(atk, def, hp, symbol), isHostile(isHostile) {}

bool Enemy::isEnemyHostile() { return isHostile; }


void Enemy::attackPlayer(Player* player) {
	int i = rand() % 2;
	string newAction;
	if (!player) {}//cout << "No enemy to attack at that position!" << endl;
	else if (i) {
		int damageDealt = ceil((100/(100 + float(player->getDef())))* float(this->getAtk()));
		newAction = player->getAction() + "Damage done by " + this->getSymbol() + " to " + player->getSymbol() + ": " +  to_string(damageDealt) + "HP. ";
		player->setAction(newAction);
		player->setHp(player->getHp() - damageDealt );
	}
	else{
			newAction = player->getAction() + " " + this->getSymbol()+ " missed its attack! ";
			player->setAction(newAction);
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
