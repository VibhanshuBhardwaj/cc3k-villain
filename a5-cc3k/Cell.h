#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>
#include <string>
#include "Character/Character.h"
#include "Item/Item.h"

class Character;
class Item;

class Cell {

	  int row;
	  int col;
    char symbol;
	  std::string type; // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR
	  bool occupied;
    //char whoOccupied;
    Character * whoOccupied;
    Item *it;
  public:
    Cell();
  	Cell(int row, int col, char sym, std::string type);
    bool dragonHoard;
    void occupy(Character * whoOccupied);
    void occupy(Item *itm);
    void leave();
  	bool isOccupied();
  	bool setOccupied(bool ev);
    bool atStairs();
  	void setType(std::string t);
    char getSymbol();
    void setSymbol(char ch);
    bool playerMoveValid();
    bool enemyMoveValid();
    int getRow();
    int getCol();
    bool isGold();
    bool isPotion();
    Character * getCharacter();
    Item * getItem();
};


#endif

