#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race): Character(atk, def, hp, '@'), race(race) {
	levelDef = def;
	levelAtk = atk;
	action = "";
	score = 0;
}

int Player::getScore(){ return score; }

void Player::setScore(int newScore){ score = newScore; }

int Player::getLevelDef()  { return levelDef; }

int Player::getLevelAtk() { return levelAtk; }

void Player::setLevelDef(int newlevelDef) { levelDef = newlevelDef; }

void Player::setLevelAtk(int newlevelAtk) { levelAtk = newlevelAtk; }

string Player::getRace() { return race; }

string Player::getAction() { return action; }

void Player::setAction(string newAction) {
	action = newAction;
}

void Player::reset() {
	//health is permanent
	setAtk(levelAtk); //Level Attack is the value of attack which is 
					  //DEFAULT value at the start of every level
	setDef(levelDef);//Level Defence is the value of defence which is 
					  //DEFAULT value at the start of every level
}

string Player::usePotion(Item *it){
	string result = "";
	if(it && (it->getType()=="PH" || it->getType()=="RH"||it->getType()=="BA" ||it->getType()=="BD"||it->getType()=="WD"||it->getType()=="WA")){

		it->use(this); //use potion on this player
		result = " Potion used. Potion Type: (" + it->getType() +"). ";
		it->setVisited();
		Cell *c = it->getCurrCell();
		c->leave(); //leave the cell
	}
	return result;
}

void Player::attack(Character* victim) {
	int i = rand() % 2;
	if (!victim) action = getAction() + "No enemy to attack at that position! ";

	else if (victim->getSymbol() == 'L' && i) {action = getAction() + "Player missed its attack on Halfling. "; return; }

	else {
		if (victim->getSymbol() == 'M') {
			if(!victim->isEnemyHostile()){
				victim->makeHostile();
				action += "Merchants are now hostile. " ;
			}
		}
		int damageDealt = ceil((100/(100 + float(victim->getDef())))* float(this->getAtk()));
		action = getAction() + "Damage done by " + this->getRace() + " to " +victim->getSymbol()+ ": " + to_string(damageDealt) + "HP. ";
		//cout << "old victim hp" << victim->getHp() << endl;
		victim->setHp(victim->getHp() - damageDealt); //the 20 is temporary to fasten the death of victim
		//cout << "new victim hp" << victim->getHp() << endl;

		if (!victim->isAlive()) {
      if(this->getRace() == "Goblin"){
				this->setScore(this->getScore() + 5); //NOTE CONFIRM
			}
      victim->onDeath(this);
      
    }

	}
}

void Player::onMove() {
}
void Player::onDeath(Player * p) {}
void Player::onAttack() {}

Player::~Player() {}
