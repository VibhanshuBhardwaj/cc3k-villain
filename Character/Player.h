#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>

class Player{
	int row;
	int col;
	char playerChar;
  public:
  	Player();
  	Player(int row, int col);
  	void posUpdate(int r, int c);
  	std::vector<int> getPos();
};

#endif