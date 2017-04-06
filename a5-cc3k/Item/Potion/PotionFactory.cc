#include "PotionFactory.h"
#include <cstdlib>

using namespace std;

Potion *PotionFactory::generatePotion(){
	Potion *p;
	int potId = rand() % 6 + 1;
	if(potId == 1){ 
		p = new rHealth(); //RESTORE HEALTH
	}
	else if(potId == 2){
		p = new bAttack(); //BOOST ATTACK
	}
	else if (potId == 3){
		p = new bDefence(); //BOOST DEFENCE
	}
	else if (potId == 4){
		p = new pHealth(); //POISON HEALTH
	}
	else if (potId == 5){
		p = new wAttack(); //WOUND ATTACK
	}
	else{ //POTID == 6
		p = new wDefence(); //WOUND DEFENCE
	}
	return p;
}

Potion *PotionFactory::generatePotion(char potId){
	Potion *p;
	if(potId == '0'){ 
		p = new rHealth(); //RESTORE HEALTH
	}
	else if(potId == '1'){
		p = new bAttack(); //BOOST ATTACK
	}
	else if (potId == '2'){
		p = new bDefence(); //BOOST DEFENCE
	}
	else if (potId == '3'){
		p = new pHealth(); //POISON HEALTH
	}
	else if (potId == '4'){
		p = new wAttack(); //WOUND ATTACK
	}
	else if (potId == '5'){ //POTID == 6
		p = new wDefence(); //WOUND DEFENCE
	}
	return p;
}

