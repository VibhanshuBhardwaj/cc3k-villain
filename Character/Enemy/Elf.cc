#include <string>
#include "Elf.h"

using namespace std;

Elf::Elf(int atk, int def, int hp): Enemy(atk, def, hp, 'E', true) {}
void Elf::attackPlayer(Player *player) {
	if (player->getRace() != "Drow"){ //elf gets two attacks on every player except drow
		cout << "elf not attacking drow" << endl;
		Enemy::attackPlayer(player);
		Enemy::attackPlayer(player);
	}
	else {
		cout << "elf attacking drow" << endl;
		Enemy::attackPlayer(player);
	}
}
