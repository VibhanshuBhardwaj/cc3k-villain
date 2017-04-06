#include "BDefence.h"

//BOOST DEFENCE
bDefence::bDefence(){
	visited = false;
}
bool bDefence::getVisited(){
	return visited;
}
void bDefence::setVisited(){
	visited = true;
}
void bDefence::use(Player *pc){
	pc->setDef(pc->getDef() + 5);
}


