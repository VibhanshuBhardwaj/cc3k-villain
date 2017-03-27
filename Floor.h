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
#include "character/Player.h"
#include "character/Enemy.h"

class Game;

class Floor{
	//std::string maps[25]; // map is a 2d array of characters 
					     // map accurately represents the Floor 
	std::vector<std::vector < Cell* > > grid;
	Player *player; //pointer to player object
	std::vector<Enemy*> enemies; //vector of 20 enemies
	//potions 10
	//gold 10
	std::string action;
	std::string playerRace; 
	Chamber chambers[5]; //array of 5 chambers

  public:
	Floor(std::string file, std::string playerRace); //replace string playerRace with Player reference
	void printFloor();
	bool enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex);
	bool playerMoved(int row, int col, int prevRow, int prevCol);
	void playerMove(std::string dir);
	void enemyMove();
	/*void usePotion(std::string dir);
	void atkDirection(std::string dir);
	void freezeEnemy();
	void unfreezeEnemy();*/
	std::vector<int> getRandPos(int chamberId);
	bool isValid(int x, int y);
	void insert(int x, int y, char ch);
	void spawnPlayer();
	void spawnStairs();
	void spawnPotions();
	void spawnGold();
	void spawnEnemies();
	~Floor();
};


#endif