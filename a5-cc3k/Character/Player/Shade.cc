#include <string>
#include "Shade.h"

using namespace std;

Shade::Shade(int hp, int atk, int def): Player(hp, atk, def, "Shade") {}

// void Shade::attack(Character* victim) {
// 	if (!victim) cout << "No enemy to attack at that position!" << endl;
// 	else {
// 		float damageDealt = (100/(100 + float(victim->getDef())))* float(this->getAtk());
// 		cout << "damageDealt by shade: " << damageDealt << " to "<< victim->getSymbol() << endl;
// 		cout << "old victim hp" << victim->getHp() << endl;
// 		victim->setHp(victim->getHp() - damageDealt );
// 		cout << "new victim hp" << victim->getHp() << endl;

// 	}
// }

