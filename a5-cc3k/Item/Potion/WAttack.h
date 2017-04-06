#ifndef __WATTACK_H__
#define __WATTACK_H__
#include "Potion.h"

class wAttack : public Potion{
	static bool visited;
public:
	wAttack();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};


#endif
