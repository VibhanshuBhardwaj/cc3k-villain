#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>
#include <string>

class Cell {

	  int row;
	  int col;
    char symbol;
	  std::string type; // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR 
	  bool occupied;
    char whoOccupied; 

  public:
    Cell();
  	Cell(int row, int col, char sym, std::string type);
    void occupy(char ch);
    void leave();
  	bool isOccupied();
  	bool setOccupied(bool ev);
  	void setType(std::string t);
    char getSymbol();
    bool playerMoveValid();
    bool enemyMoveValid();
};


#endif
