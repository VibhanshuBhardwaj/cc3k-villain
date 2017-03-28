#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "character.h"
#include <string>

class Player: public Character {
	std::string race;
	int levelDef;
	int levelAtk;

public:
	Player(int hp, int atk, int def, std::string race);
	virtual ~Player();

	int getLevelAtk();
	int getLevelDef();

	void setLevelAtk(int levelAtk);
	void setLevelDef(int levelDef);

	void reset(); // when new level begins
	std::string getRace();

};

#endif