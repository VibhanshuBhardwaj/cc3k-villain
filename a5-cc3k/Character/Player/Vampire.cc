#include <string>
#include "Vampire.h"

using namespace std;

Vampire::Vampire(int hp, int atk, int def): Player(hp, atk, def, "Vampire") {}
void Vampire::onAttack(char victimSymbol) {
	if (victimSymbol == 'W') setHp(getHp() - 5); //vampires LOSE 5 hp when they attack dwarves
	else setHp(getHp() + 5);
	//cout << "vampire onAttack called. hp increased " << endl;
}

void Vampire::attack(Character* victim) {
	Player::attack(victim);
	onAttack(victim->getSymbol());
}

