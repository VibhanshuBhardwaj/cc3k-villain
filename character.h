#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <vector>
#include <string>
#include <iostream>
#include "cell.h"
class Cell;

class Character {
	int atk;
	int def;
	int hp;
	char symbol;
public:
	Character();
	Character(int atk, int def, int hp, char symbol);
	bool isAlive();

	void setHp(int newHp);
	void setAtk(int newAtk);
	void setDef(int newDef);
	Cell *currPos; //is a reference better here?
	int getHp();
	int getAtk();
	int getDef();

	//virtual void move(std::string dir) = 0;
	virtual ~Character();

};

#endif