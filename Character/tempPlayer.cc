#include "Player.h"

#include <vector>

using namespace std;
Player::Player(){}

Player::Player(int row, int col): row{row}, col{col}{
	score = 0;
	//different races will have different stats***
	hp = 0;
	atk = 0;
	def = 0;
}

void Player::posUpdate(int r, int c){
	row = r;
	col = c;
}

vector<int> Player::getPos(){
	vector<int> pos;
	pos.emplace_back(col);
	pos.emplace_back(row);
	return pos;
}

int Player::getScore(){
	return score; 
}

int Player::getAtk(){
	return atk;
}

int Player::getHp(){
	return hp;
}

int Player::getDef(){
	return def;
}
