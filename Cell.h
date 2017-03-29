#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>
#include <string>
#include "Character/Character.h"

class Character;

class Cell {

	  int row;
	  int col;
    char symbol;
	  std::string type; // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR
	  bool occupied;
    //char whoOccupied;
    Character * whoOccupied;


  public:
    Cell();
  	Cell(int row, int col, char sym, std::string type);
    void occupy(Character * whoOccupied);
    void leave();
  	bool isOccupied();
  	bool setOccupied(bool ev);
  	void setType(std::string t);
    char getSymbol();
    bool playerMoveValid();
    bool enemyMoveValid();
    int getRow();
    int getCol();
    void setSymbol(char ch);
};


#endif
