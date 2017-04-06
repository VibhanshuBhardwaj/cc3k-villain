
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../Cell.h"

#include "Character.h"

using namespace std;

Character::Character() {}

Character::Character(int atk, int def, int hp, char symbol): atk{atk}, def{def}, hp{hp}, symbol{symbol} {
	maxHp = hp;
}

int Character::getHp() { return hp; }
int Character::getAtk() { return atk; }
int Character::getDef() { return def; }

bool Character::isAlive() { return hp > 0; }

void Character::setHp(int newHp, bool isDlcEnabled) {
    if( newHp < 0){
		hp = 0;
	}
	if (isDlcEnabled) {
		maxHp = newHp;
		hp = newHp;
	}
	else if (currCell->getCharacter()->getRace() == "Vampire") {
		hp = newHp;
		//cout << "is Vampire. new hp: " << hp << endl;
	}

  else if(newHp > maxHp){
		hp = maxHp;
	}
	else {
		hp = newHp;
		//cout << "not vampire. new hp: " << hp << endl;
	}
}
void Character::makeHostile() {}

void Character::setAtk(int newAtk) { atk = newAtk; }

void Character::setDef(int newDef) { def = newDef; }

bool Character::isEnemyHostile(){return false;}
char Character::getSymbol() { return symbol; }

Cell* Character::getCurrCell() { return currCell; }

void Character::setCurrCell(Cell* newCell) {
	currCell = newCell;
}
void Character::onDeath(Player * p) {}

Character::~Character() {}

