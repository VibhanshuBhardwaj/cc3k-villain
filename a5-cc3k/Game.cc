#include "Game.h"
#include <string>
#include <iostream>
#include "Character/Player/PlayerFactory.h"
using namespace std;


//class Floor;
//class Chamber;
Game::Game(){}

Game::Game(string pRace, string fName){ //initialize a new game
	floorLevel = 1;
	fileName = fName;
	PlayerFactory pf = PlayerFactory();
	if(pRace == "s"){
		playerRace = "Shade";
	}
	else if(pRace == "d"){
		playerRace = "Drow";
	}
	else if(pRace == "v"){
		playerRace = "Vampire";
	}
	else if(pRace == "t"){
		playerRace = "Troll";
	}
	else if (pRace == "r") {
		playerRace = "Rut";
	}
	else {
		playerRace = "Goblin";
	}

	player = pf.generatePlayer(playerRace);
	floor = new Floor(fileName, playerRace, player, floorLevel); //(fileName, replace with player*)
	printGame();
}

void Game::printGame(){
	floor->printFloor();
	floor->printStats();
	cout << "Action: " << action << floor->getAction() << endl;
	floor->setAction("");
}

void Game::setPlayerHp(int newHp) {
	player->setHp(newHp, true);
}
void Game::setPlayerAction( string newAction) {
	player->setAction(newAction);
}
string Game::getPlayerAction() {
	return player->getAction();
}

void Game::boostPlayerAtk(int boost) {
	player->setAtk(player->getAtk() + boost);
}
void Game::boostPlayerDef(int boost) {
	player->setDef(player->getDef() + boost);
}
void Game::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw
	floor->playerMove(dir);
	if(floor->atStairs()){
		//player reached the stairs
		if(floorLevel < 6){
			floorLevel++;
			delete floor;
			string s = to_string(floorLevel);
			action = "Floor " + s + " Generated! ";
			player->reset();
			floor = new Floor(fileName, playerRace, player, floorLevel);
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


void Game::usePotion(string dir){
	floor->usePotion(dir);
	printGame();
}

void Game::atkDirection(string dir){
	floor->atkDirection(dir);
	printGame();
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
	delete player;
}
