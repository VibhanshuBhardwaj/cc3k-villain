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