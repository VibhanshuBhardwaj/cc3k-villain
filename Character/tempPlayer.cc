#include "Player.h"

#include <vector>

using namespace std;
Player::Player(){}

Player::Player(int row, int col): row{row}, col{col}{}

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