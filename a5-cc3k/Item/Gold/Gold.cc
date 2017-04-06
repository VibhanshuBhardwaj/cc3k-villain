#include "Gold.h"

using namespace std;

Gold::Gold(): Item(){}
Gold::Gold(string type, int value, bool available): Item(type), value{value}, available{available}{}

char Gold::getSymbol(){

	return 'G';
}
bool Gold::getVisited(){return true; }
bool Gold::isAvailable(){
	return available;
}
void Gold::setAvailable(){ available = true; }
void Gold::setVisited(){}
void Gold::use(Player *pc){
	pc->setScore(pc->getScore() + value);
}


//SMALL PILE GOLD
smallPile::smallPile(): Gold(" Small Pile of Gold. ", 1, true){}

//NORMAL PILE GOLD
normalPile::normalPile(): Gold(" Normal Pile of Gold. ", 2, true){}

//MERCHANT HOARD
merchantHoard::merchantHoard(): Gold(" Merchant Hoard. ", 4, true){}

//HUMAN PILE 
humanPile::humanPile(): Gold(" Human Pile of Gold. ", 4, true){}
//DRAGON HOARD
dragonHoard::dragonHoard(): Gold(" Dragon Hoard. ", 6, false){}




