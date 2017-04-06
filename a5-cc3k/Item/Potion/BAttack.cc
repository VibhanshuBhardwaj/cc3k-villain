#include "BAttack.h"
//BOOST ATTACK
bAttack::bAttack(){
	visited = false;
}
bool bAttack::getVisited(){
	return visited;
}
void bAttack::setVisited(){
	visited = true;
}
void bAttack::use(Player *pc){
	pc->setAtk(pc->getAtk() + 5);
}


