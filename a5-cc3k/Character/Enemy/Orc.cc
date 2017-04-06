#include <string>
#include "Orc.h"

using namespace std;

Orc::Orc(int atk, int def, int hp): Enemy(atk, def, hp, 'O', true) {}
void Orc::attackPlayer(Player* player) {
	if (!player) {}//cout << "No enemy to attack at that position!" << endl;
	else {
		int damageDealt = ceil((100/(100 + float(player->getDef())))* float(this->getAtk()));
		if (player->getRace() =="Goblin") { //orcs do 50% more damage to goblins
			damageDealt = 1.5 * damageDealt;
			//cout << "orc attacking goblin" << endl;
		}
		string newAction = player->getAction() + "Damage done by " + this->getSymbol() + " to " + player->getSymbol() + ": " +  to_string(damageDealt) + "HP. ";
		player->setAction(newAction);
		//cout << "old player hp" << player->getHp() << endl;
		player->setHp(player->getHp() - damageDealt );
		//cout << "new player hp" << player->getHp() << endl;

	}
}

