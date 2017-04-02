#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "Enemy.h"
#include "../../Item/Gold/Gold.h"

//class Gold;

class Dragon : public Enemy{
public: 
	Gold *hoard;
	Dragon(int atk = 20, int def = 20, int hp = 180, Gold *dh = nullptr);
	void onDeath(Player * p);
};

#endif