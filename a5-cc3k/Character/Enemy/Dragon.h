#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "Enemy.h"
#include "../../Item/Item.h"
//class Gold;

//class Gold;

class Player;
class Dragon : public Enemy{
public: 
	Item *hoard;
	Dragon(int atk = 20, int def = 20, int hp = 180, Item *dh = nullptr);
	void onDeath(Player * p) override;
};

#endif
