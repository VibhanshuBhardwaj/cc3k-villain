#include <iostream>
#include "Player.h"
#include "Character.h"

using namespace std;

Player::Player(int hp, int atk, int def, string race): Character(hp, atk, def, '@'), race(race), levelDef(0), levelAtk(0) {}

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

Player::~Player() {}