#include "RHealth.h"
using namespace std;

//RESTORE HEALTH
rHealth::rHealth(){
	visited = false;
}
bool rHealth::getVisited(){
	return visited;
}
void rHealth::setVisited(){
	visited = true;
}
void rHealth::use(Player *pc){
	pc->setHp(pc->getHp() + 10);
}

