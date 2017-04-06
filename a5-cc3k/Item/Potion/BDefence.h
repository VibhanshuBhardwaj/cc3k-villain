#ifndef __BDEFENCE_H__
#define __BDEFENCE_H__

#include "Potion.h"

class bDefence : public Potion{
	static bool visited;
public:
	bDefence();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};


#endif
