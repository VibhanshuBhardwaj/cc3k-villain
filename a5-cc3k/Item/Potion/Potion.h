#ifndef __POTION_H__
#define __POTION_H__

#include "../Item.h"
#include "../../Character/Player/Player.h"

//class Player;

class Potion : public Item {
	//std::string type; // RH BA BD PH WA WD
  public:
  	Potion();     
    Potion(std::string type);     
    char getSymbol() override; 
    void use(Player *pc) override;
    bool getVisited() override;
    void setVisited() override;
    bool isAvailable() override;
    void setAvailable() override;
    //std::string getType();
};

//RESTORE HEALTH
class rHealth : public Potion{
	static bool visited;
public:
	rHealth();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};

class bAttack : public Potion{
	static bool visited;
public:
	bAttack();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};

class bDefence : public Potion{
	static bool visited;
public:
	bDefence();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};

class pHealth : public Potion{
	static bool visited;
public:
	pHealth();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};

class wAttack : public Potion{
	static bool visited;
public:
	wAttack();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};

class wDefence : public Potion{
	static bool visited;
public:
	wDefence();
	bool getVisited() override;
	void setVisited() override;
	void use(Player *pc) override;
};



#endif
