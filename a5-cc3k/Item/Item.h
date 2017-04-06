#ifndef __ITEM_H__
#define __ITEM_H__
#include <vector>
#include <string>
#include <iostream>

class Cell;
class Player;

class Item{
	Cell *currCell;
	std::string type;
  public:
  	Item();
  	Item(std::string type);
  	virtual char getSymbol() = 0;
  	virtual void use(Player *pc) = 0;
    virtual bool getVisited() = 0;
    virtual void setVisited() = 0;
    virtual bool isAvailable() = 0;
    virtual void setAvailable() = 0;
	Cell * getCurrCell();
	std::string getType(); 
	void setCurrCell(Cell* newCell); //USE ITEM ON PLAYER CHARACTER 
									      //PURE VIRTUAL METHOD      
	~Item();
};

#endif
