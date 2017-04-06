#ifndef _PLAYERFACTORY_H
#define _PLAYERFACTORY_H
#include "Player.h"

class PlayerFactory {
public:
	Player * generatePlayer(std::string race);
};

#endif
