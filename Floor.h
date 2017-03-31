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

class Game;

class Floor{
	//std::string maps[25]; // map is a 2d array of characters
					     // map accurately represents the Floor
	std::vector<std::vector < Cell* > > grid;
	Player *player; //pointer to player object
	std::vector<Enemy*> enemies; //vector of 20 enemies
	//potions 10
	//gold 10
	int playerSpawnedChamber;
	std::string action;
	std::string playerRace;
	int floorLevel;
	bool freeze;
	Chamber chambers[5]; //array of 5 chambers
	Cell* findCell(int row, int col);

  public:
	Floor(std::string file, std::string playerRace, int fLevel); //replace string playerRace with Player reference
	bool enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex);
	bool playerMoved(int row, int col, int prevRow, int prevCol, std::string dir);
	void playerMove(std::string dir);
	void enemyMove();
	bool atStairs();
	/*void usePotion(std::string dir);*/
	void atkDirection(std::string dir);
	void freezeEnemy();
	void unfreezeEnemy();
	std::vector<int> getRandPos(int chamberId);
	bool isValid(int x, int y);
	void insertSymbol(int x, int y, char ch);
	void insertCharacter(int x, int y, Character* ch);
	void spawnPlayer();
	void spawnStairs();
	void spawnPotions();
	void spawnGold();
	void spawnEnemies();
	void printStats();
	bool canEnemyAttackPlayer(Enemy *);
	std::string getAction();
	void setAction(std::string ac);
	void printFloor();
	~Floor();
};


#endif