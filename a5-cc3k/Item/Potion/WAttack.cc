#include "WAttack.h"

//WOUND ATTACK
wAttack::wAttack(){
	visited = false;
}
bool wAttack::getVisited(){
	return visited;
}
void wAttack::setVisited(){
	visited = true;
}
void wAttack::use(Player *pc){
	pc->setAtk(pc->getAtk() - 5);
}

