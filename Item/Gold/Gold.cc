#include "Gold.h"

using namespace std;

Gold::Gold(): Item(){}
Gold::Gold(string type, int value): Item(type), value{value}{}

char Gold::getSymbol(){
	return 'G';
}
bool Gold::getVisited(){return true; }
bool Gold::isAvailable(){
	return available;
}
void Gold::setVisited(){}
void Gold::use(Player *pc){
	pc->setScore(pc->getScore() + value);
}


//SMALL PILE GOLD
smallPile::smallPile(): Gold(" Small Pile of Gold. ", 1){}

//NORMAL PILE GOLD
normalPile::normalPile(): Gold(" Normal Pile of Gold. ", 2){}

//MERCHANT HOARD
merchantHoard::merchantHoard(): Gold(" Merchant Hoard. ", 4){}

//DRAGON HOARD
dragonHoard::dragonHoard(): Gold(" Dragon Hoard. ", 6){}



