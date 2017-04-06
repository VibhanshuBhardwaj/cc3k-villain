#include "GoldFactory.h"
using namespace std;

Gold * GoldFactory::generateGold(){
	Gold *g;
	int goldId = rand() % 8; //generate random number between 0 - 7 (inclusive)
	if(goldId >= 0 && goldId <= 4) g = new normalPile();
	else if(goldId == 5) g = new dragonHoard();
	else  g = new smallPile(); //gold id == 6 7
	return g;
}	

Gold * GoldFactory::generateGold(char id){
	Gold *g;
	if(id == '6') g = new normalPile();
	else if(id == '7') g = new smallPile();
	else  if(id == '8') g = new merchantHoard();
	else if(id == '9') g = new dragonHoard();
	return g;
}	
