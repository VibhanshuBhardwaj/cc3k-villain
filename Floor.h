#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <string>
#include <vector>
#include "Chamber.h"

class Game;

class Floor{
	std::string maps[25]; // map is a 2d array of characters 
					     // map accurately represents the Floor 
	//Player *player; //pointer to player object
	//Enemy enemies[20]; //array of 20 enemies
	//potions 10
	//gold 10
	std::string playerRace; 
	Chamber chambers[5]; //array of 5 chambers

  public:
	Floor(std::string file, std::string playerRace); //replace string playerRace with Player reference
	void printFloor();
	/*void playerMove(std::string dir);
	void usePotion(std::string dir);
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