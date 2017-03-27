#ifndef __CELL_H__
#define __CELL_H__

#include <iostream>
#include <map>

class Cell {

	  int row;
	  int col;
	  std::string type; // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR 
	  char symbol;
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
    bool playerMovePossible();
    bool enemyMovePossible();
};


#endif
