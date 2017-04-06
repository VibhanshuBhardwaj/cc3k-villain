#ifndef __GOLD_H__
#define __GOLD_H__

#include "../Item.h"
#include "../../Character/Player/Player.h"

class Gold : public Item {
	//std::string type; // RH BA BD PH WA WD
	int value; //value to be added to the player score
	bool available;
  public:			
  	Gold();
    Gold(std::string type, int value, bool available);     
    char getSymbol() override; 
    void use(Player *pc) override;
    bool getVisited() override;
    void setVisited() override;
    bool isAvailable() override;
    void setAvailable() override;
    //std::string getType();
};

class smallPile : public Gold{
public: 
	smallPile();
};

class normalPile : public Gold{
public: 
	normalPile();
};

class merchantHoard : public Gold{
  public: 
	merchantHoard();
};

class humanPile : public Gold{
public:
  humanPile();
};

class dragonHoard : public Gold{
public:
	dragonHoard();
};


#endif
