#include <iostream>
#include <string>
#include <vector>
#include "Cell.h"
#include "Character.h"

using namespace std;

Character::Character() {}

Character::Character(int atk, int def, int hp, char symbol): atk{atk}, def{def}, hp{hp}, symbol{symbol} {}

int Character::getHp() { return hp; }
int Character::getAtk() { return atk; }
int Character::getDef() { return def; }

bool Character::isAlive() { return hp != 0; }

void Character::setHp(int newHp) { hp = newHp; }

void Character::setAtk(int newAtk) { atk = newAtk; }

void Character::setDef(int newDef) { def = newDef; }

char Character::getSymbol() { return symbol; }

Cell* Character::getCurrCell() { return currCell; }

void Character::setCurrCell(Cell* newCell) {
	currCell = newCell;
}

Character::~Character() {}
