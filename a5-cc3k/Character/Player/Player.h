#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <vector>
#include "../Character.h"
#include <string>


class Item;
class Potion;
class Character;
//class Merchant;

class Player: public Character {
	std::string race;
	int score;
	int levelDef;
	int levelAtk;
	std::string action;

public:
	Player(int hp, int atk, int def, std::string race);
	virtual ~Player();
	int getScore(); //GOLD PILES
	void setScore(int newScore);

	int getLevelAtk();
	int getLevelDef();

	void setLevelAtk(int levelAtk);
	void setLevelDef(int levelDef);
	virtual void attack(Character* victim);
	std::string usePotion(Item *it);
	void reset(); // when new level begins
	void setAction(std::string newAction);
	virtual void onMove();
	virtual void onAttack();
	virtual void onDeath(Player * p) override;
	std::string getAction();
	std::string getRace();

};

#endif
