#include "WDefence.h"


//WOUND DEFENCE
wDefence::wDefence(){
	visited = false;
}
bool wDefence::getVisited(){
	return visited;
}
void wDefence::setVisited(){
	visited = true;
}
void wDefence::use(Player *pc){
	pc->setDef(pc->getDef() - 5);
}


