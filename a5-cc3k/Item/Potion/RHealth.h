#ifndef __RHEALTH_H__
#define __RHEALTH_H__

#include "Potion.h"

class rHealth : public Potion{
	static bool visited;
public:
	rHealth();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};

#endif
