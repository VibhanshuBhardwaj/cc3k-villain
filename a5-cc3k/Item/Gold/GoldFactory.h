#ifndef __GOLDFACTORY_H__
#define __GOLDFACTORY_H__

#include "Gold.h"

class smallPile;
class normalPile;
class merchantHoard;
class dragonHoard;

class GoldFactory{
public:
	Gold * generateGold();
	Gold * generateGold(char id);
};



#endif
