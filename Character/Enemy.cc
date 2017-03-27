#include "Enemy.h"

#include <vector>

using namespace std;
Enemy::Enemy(){}

Enemy::Enemy(int row, int col, char enemyChar): row{row}, col{col}, enemyChar{enemyChar}{}

void Enemy::posUpdate(int r, int c){
	row = r;
	col = c;
}

vector<int> Enemy::getPos(){
	vector<int> pos;
	pos.emplace_back(col);
	pos.emplace_back(row);
	return pos;
}

bool Enemy::isAlive(){
	//TO IMPLEMENT. RELATE HP
	return true;
}

char Enemy::getSymbol(){
	return enemyChar;
}