#include "Game.h"
#include "Floor.h"
#include <string>
#include <iostream>
using namespace std;

//class Floor;
//class Chamber;
Game::Game(){}

Game::Game(string pRace, string fName){ //initialize a new game
	floorLevel = 1;
	fileName = fName;
	if(pRace == "s"){playerRace = "Shade";}
	else if(pRace == "d"){playerRace = "Drow";}
	else if(pRace == "v"){ playerRace = "Vampire";}
	else if(pRace == "t"){playerRace = "Troll";}
	else {playerRace = "Goblin";}
	floor = new Floor(fileName, playerRace, floorLevel); //(fileName, replace with player*)
	printGame();
}

void Game::printGame(){
	floor->printFloor();
	floor->printStats();
	cout << "Action: " << action << floor->getAction() << endl;
	//cout << "Action: " << floor->getAction() << endl;
	floor->setAction("");
}

void Game::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw
	floor->playerMove(dir);
	if(floor->atStairs()){
		cout << "at stairs" << endl;
		cout << floorLevel << endl;
		//player reached the stairs
		if(floorLevel < 6){
			floorLevel++;
			delete floor;
			string s = to_string(floorLevel);
			action = "Floor " + s + " Generated! ";
			floor = new Floor(fileName, playerRace, floorLevel);
		}
		if(floorLevel == 6){
			//reached the stairs of last level;
			cout << "Cc3K GaMe WoN. " << endl;
			cout << "CoNgRaTuLaTiOnS!!!"<< endl;
		}

	}
	if(floorLevel < 6){
		printGame();
		action = "";
	}
}

/*
void Game::usePotion(string dir){
	floor->usePotion(dir);
}
*/
void Game::atkDirection(string dir){
	floor->atkDirection(dir);
	printGame(); //NOT SURE!!!!!!!! ATTENTION
}


void Game::freezeEnemy(){
	floor->freezeEnemy();
    printGame();
}

void Game::unFreezeEnemy(){
	floor->unfreezeEnemy();
    printGame();
}

bool Game::isWon(){
	if(floorLevel == 6){
		//above 5th Floor
		return true;
	}
	return false;
}

bool Game::isAlive(){
	//To Implement after character class is completed *******<<< . >>>***
	return floor->isPlayerAlive();
	// if(floor > 0)return true;
	// else return false;
	//return true;
}

Game::~Game(){
	delete floor;
}