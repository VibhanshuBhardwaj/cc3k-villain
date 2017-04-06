#include "PHealth.h"
//POISON HEALTH
pHealth::pHealth(){
	visited = false;
}
bool pHealth::getVisited(){
	return visited;
}
void pHealth::setVisited(){
	visited = true;
}
void pHealth::use(Player * pc){
	pc->setHp(pc->getHp() - 10);
}


