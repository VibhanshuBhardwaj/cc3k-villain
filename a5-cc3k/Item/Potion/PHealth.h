#ifndef __PHEALTH_H__
#define __PHEALTH_H__
#include "Potion.h"


class pHealth : public Potion{
	static bool visited;
public:
	pHealth();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};


#endif
