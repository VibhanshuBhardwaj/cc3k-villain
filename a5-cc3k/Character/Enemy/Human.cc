#include <string>
#include "Human.h"
#include "../../Item/Gold/Gold.h"

using namespace std;

Human::Human(int atk, int def, int hp): Enemy(atk, def, hp, 'H', true) {}

void Human::onDeath(Player * p) {
	this->getCurrCell()->leave();
	Gold * g = new humanPile();
	getCurrCell()->occupy(g);
}
