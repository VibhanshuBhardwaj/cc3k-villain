#include "PlayerFactory.h"

#include "Drow.h"
#include "Goblin.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Rut.h"
#include "string"

#include <stdexcept>

using namespace std;

Player* PlayerFactory::generatePlayer(string race) {
	if (race ==  "Shade" ) {
		return new Shade();
	}
	else if (race ==  "Drow" ) {
		return new Drow();
	}
	else if (race ==  "Goblin" ) {
		return new Goblin();
	}
	else if (race ==  "Troll" ) {
		return new Troll();
	}
	else if (race ==  "Vampire") {
		return new Vampire();
	}
	else if (race  == "Rut") {
		return new Rut();
	}
	else throw invalid_argument("race for generating player does not exist. Exiting"); //should NEVER happen

}
