#ifndef _POTIONFACTORY_H__
#define _POTIONFACTORY_H__

#include "Potion.h"


class rHealth;
class bAttack;
class bDefence;
class pHealth;
class wAttack;
class wDefence;

class PotionFactory{
public: 
	Potion *generatePotion();
	Potion *generatePotion(char potId);
};


#endif
