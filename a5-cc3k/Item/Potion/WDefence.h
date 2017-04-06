#ifndef __WDEFENCE_H__
#define __WDEFENCE_H__
#include "Potion.h"


class wDefence : public Potion{
	static bool visited;
public:
	wDefence();
	bool getVisited();
	void setVisited();
	void use(Player *pc) override;
};


#endif
