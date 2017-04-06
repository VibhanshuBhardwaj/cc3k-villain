#ifndef __GAME_H__
#define __GAME_H__
#include <string>
#include <iostream>
#include "Floor.h"
#include "Chamber.h"
#include "Character/Player/Player.h"
#include "Character/Player/Shade.h"
#include "Character/Player/Drow.h"
#include "Character/Player/Goblin.h"
#include "Character/Player/Vampire.h"
#include "Character/Player/Troll.h"
//class Chamber;

class Game{
	std::string playerRace;
	std::string fileName;
	int floorLevel;
	Floor *floor;
	std::string action;
	Player *player; //reference to a player object

  public:
  	Game();
	Game(std::string pRace, std::string fName);
	void playerMove(std::string dir); //move the player to a given direction
	void usePotion(std::string dir); //use potion if it exists at the given direction
	void atkDirection(std::string dir); //attack the player if it exists at the given direction
	void printGame();
	void freezeEnemy(); //stop the enemies from moving
	void unFreezeEnemy(); //free the enemies. Allow them to move freely
	bool isWon(); // player has won the game.
	~Game();
	void setPlayerAction(std::string newAction);
	void boostPlayerAtk(int boost);
	void boostPlayerDef(int boost);
	void setPlayerHp(int newHp);
	std::string getPlayerAction();
	bool isAlive();
};

#endif
