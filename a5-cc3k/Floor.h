#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Chamber.h"
#include "Cell.h"
#include "Character/Player/Player.h"
#include "Character/Enemy/Enemy.h"
#include "Character/Character.h"
#include "Item/Item.h"
#include "Item/Potion/Potion.h"
#include "Character/Enemy/Dragon.h"
#include "Item/Gold/Gold.h"

class Game;

class Floor{
	//std::string maps[25]; // map is a 2d array of characters
					     // map accurately represents the Floor
	std::vector<std::vector < Cell* > > grid;
	Player *player; //pointer to player object
	std::vector<Dragon*> dragons;
	std::vector<Enemy*> enemies; //vector of 20 enemies
	std::vector<Potion*> potions;
	std::vector<Gold*> golds;
	//gold 10
	int playerSpawnedChamber;
	std::string fileName;
	std::string action;
	std::string playerRace;
	int floorLevel;
	bool freeze;
	Chamber chambers[5]; //array of 5 chambers
	Cell* findCell(int row, int col);

  public:
	Floor(std::string file, std::string playerRace, Player *p, int fLevel); //replace string playerRace with Player reference
	bool enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex);
	void generateCustomFloor();
	void dhAssign();
	void trollUpdate();
	bool playerMoved(int row, int col, int prevRow, int prevCol, std::string dir);
	void playerMove(std::string dir);
	void enemyMove();
	bool atStairs();
	void checkPotion();
	bool isPotion(int x, int y);
	void usePotion(std::string dir);
	void atkDirection(std::string dir);
	void freezeEnemy();
	void unfreezeEnemy();
	bool isPlayerAlive();
	std::vector<int> getRandPos(int chamberId);
	std::vector<int> neighbourPos(int x, int y);
	bool isValid(int x, int y);
	void insertSymbol(int x, int y, char ch);
	void insertCharacter(int x, int y, Character* ch);
	void insertPotion(int x, int y, Potion *p);
	void insertGold(int x, int y, Gold * g);
	void spawnPlayer();
	void spawnStairs();
	void spawnPotions();
	void spawnGold();
	void spawnEnemies();
	void checkDragonAttack();
	bool canDragonAttackPlayer(Dragon *d);
	void printStats();
	bool canEnemyAttackPlayer(Enemy *);
	std::string getAction();
	void setAction(std::string ac);
	void printFloor();
	~Floor();
};


#endif
