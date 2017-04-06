#include "Vib.h"

Vib::Vib(int atk, int def, int hp): Enemy(atk, def, hp, 'V', true) {
}

void Vib::onDeath(Player * p) {
	p->setAction(p->getAction() + " Vib poisoned you before dying. Your health is reduced by 20 points! ");
	p->setHp(p->getHp() - 20);
}
