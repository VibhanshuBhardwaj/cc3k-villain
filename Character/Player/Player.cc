#include <iostream>
#include "Player.h"
#include "../Character.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race): Character(atk, def, hp, '@'), race(race), levelDef(0), levelAtk(0), action("") {}

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
	levelAtk = 0;
	levelDef = 0;
}

void Player::attack(Character* victim) {
	int i = rand() % 2;
	if (!victim) action = getAction() + "No enemy to attack at that position! ";

	else if (victim->getSymbol() == 'L' && i) {action = getAction() + "Player missed its attack on Halfling"; return; }
	else {
		int damageDealt = ceil((100/(100 + float(victim->getDef())))* float(this->getAtk()));
		action = getAction() + "Damage done by " + this->getRace() + " to " +victim->getSymbol()+ ": " + to_string(damageDealt) + "HP. ";
		//cout << "old victim hp" << victim->getHp() << endl;
		victim->setHp(victim->getHp() - damageDealt); //the 20 is temporary to fasten the death of victim
		//cout << "new victim hp" << victim->getHp() << endl;
		if (!victim->isAlive()) {cout << "enemy died" << endl; victim->getCurrCell()->leave();}

	}
}
void Player::onMove() {

}
void Player::onAttack() {}

Player::~Player() {}