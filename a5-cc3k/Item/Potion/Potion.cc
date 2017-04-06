#include "Potion.h"
using namespace std;

Potion::Potion(): Item(){}

Potion::Potion(string type): Item(type){
}
bool Potion::getVisited(){
	return true;
}
void Potion::use(Player *pc){}
//string Potion::getType(){
//	return type;
//}

char Potion::getSymbol(){
	return 'P'; 
}
bool Potion::isAvailable(){return true;}
void Potion::setAvailable(){}
void Potion::setVisited(){}

//RESTORE HEALTH
bool rHealth::visited = false;
rHealth::rHealth(): Potion("RH") {
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
	if(pc->getRace() == "Drow"){
		pc->setHp(pc->getHp() + 5);
	}
}

//BOOST ATTACK
bool bAttack::visited = false;
bAttack::bAttack(): Potion("BA"){
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
	if(pc->getRace() == "Drow"){
		pc->setAtk(pc->getAtk() + 3);
	}
}

//BOOST DEFENCE
bool bDefence::visited = false;
bDefence::bDefence(): Potion("BD"){
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
	if(pc->getRace() == "Drow"){
		pc->setDef(pc->getDef() + 3);
	}
}

//POISON HEALTH
bool pHealth::visited = false;
pHealth::pHealth(): Potion("PH"){
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
	if(pc->getRace() == "Drow"){
		pc->setHp(pc->getHp() - 5);
	}
}

//WOUND ATTACK
bool wAttack::visited = false;
wAttack::wAttack(): Potion("WA"){
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
	if(pc->getRace() == "Drow"){
		pc->setAtk(pc->getAtk() - 3);
	}
}

//WOUND DEFENCE
bool wDefence::visited = false;

wDefence::wDefence(): Potion("WD"){
	visited = false;
}
bool wDefence::getVisited(){
	return visited;
}
void wDefence::setVisited(){
	visited = true;
}
void wDefence::use(Player *pc){
	pc->setDef(pc->getDef() - 5);
	if(pc->getRace() == "Drow"){
		pc->setDef(pc->getDef() - 3);
	}
}





