#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race): Character(atk, def, hp, '@'), race(race),  score(0), levelDef(0), levelAtk(0) {}

int Player::getScore(){ return score; }

void Player::setScore(int newScore){ score = newScore; }

int Player::getLevelDef()  { return levelDef; }

int Player::getLevelAtk() { return levelAtk; }

void Player::setLevelDef(int newlevelDef) { levelDef = newlevelDef; }

void Player::setLevelAtk(int newlevelAtk) { levelAtk = newlevelAtk; }

string Player::getRace() { return race; }

void Player::reset() {
	//health is permanent
	levelAtk = 0;
	levelDef = 0;
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
	if (!victim) cout << "No enemy to attack at that position!" << endl;
	else {
		float damageDealt = (100/(100 + float(victim->getDef())))* float(this->getAtk());
		cout << "damage done by " << this->getRace() << " to "<< victim->getSymbol() << " :" << damageDealt << endl;
		cout << "old victim hp" << victim->getHp() << endl;
		victim->setHp(victim->getHp() - damageDealt - 50 ); //the 20 is temporary to fasten the death of victim
		cout << "new victim hp" << victim->getHp() << endl;
		if (!victim->isAlive()) {cout << "enemy died" << endl; victim->getCurrCell()->leave();}

	}
}

Player::~Player() {}