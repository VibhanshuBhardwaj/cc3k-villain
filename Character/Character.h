#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "../Cell.h"

class Cell;

class Character {
	int maxHp;
	int atk;
	int def;
	int hp;
	char symbol;
	Cell *currCell; //is a reference better here?
public:
	Character();
	Character(int atk, int def, int hp, char symbol);
	bool isAlive();
	char getSymbol();
	void setHp(int newHp, bool isVampire = false);
	void setAtk(int newAtk);
	void setDef(int newDef);
	int getHp();
	int getAtk();
	int getDef();
	Cell * getCurrCell();
	void setCurrCell(Cell* newCell);
	//virtual void move(std::string dir) = 0;
	virtual ~Character();
	virtual std::string getRace() = 0;

};

#endif