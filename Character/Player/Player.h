#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "../Character.h"
#include <string>

class Player: public Character {
	std::string race;
	int levelDef;
	int levelAtk;
	std::string action;

public:
	Player(int hp, int atk, int def, std::string race);
	virtual ~Player();

	int getLevelAtk();
	int getLevelDef();

	void setLevelAtk(int levelAtk);
	void setLevelDef(int levelDef);
	virtual void attack(Character* victim);
	void reset(); // when new level begins
	void setAction(std::string newAction);
	std::string getAction();
	std::string getRace();

};

#endif