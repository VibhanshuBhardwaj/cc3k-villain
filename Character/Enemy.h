#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <vector>

class Enemy{
	int row;
	int col;
	char enemyChar;
	int hp; //health points
  public:
  	Enemy();
  	Enemy(int row, int col, char enemyChar);
  	void posUpdate(int r, int c);
  	std::vector<int> getPos();
  	bool isAlive();
  	char getSymbol();
};

#endif