#ifndef __BATTACK_H__
#define __BATTACK_H__

#include "Potion.h"

class bAttack : public Potion{
	static bool visited;
public:
	bAttack();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};


#endif
