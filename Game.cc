#include "Game.h"
#include "Floor.h"
#include <string>
#include <iostream>
using namespace std;

//class Floor;
//class Chamber;
Game::Game(){}

Game::Game(string pRace, string fName){ //initialize a new game 
	floorLevel = 0; //
	fileName = fName;
	if(pRace == "s"){playerRace = "Shade";}
	else if(pRace == "d"){playerRace = "Drow";}
	else if(pRace == "v"){ playerRace = "Vampire";}
	else if(pRace == "t"){playerRace = "Troll";}
	else {playerRace = "Goblin";}
	floor = new Floor(fileName, playerRace, floorLevel); //(fileName, replace with player*) 
}

void Game::printGame(){
	floor->printFloor();
}

void Game::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw
	floor->playerMove(dir);
}
/*
void Game::usePotion(string dir){
	floor->usePotion(dir);
}

void Game::atkDirection(string dir){
	floor->atkDirection(dir);
}
*/
void Game::freezeEnemy(){
	floor->freezeEnemy();
}

void Game::unFreezeEnemy(){
	floor->unfreezeEnemy();
}

bool Game::isWon(){
	if(floorLevel > 4){
		//above 5th Floor
		return true;
	}
	return false;
}

bool Game::isAlive(){
	//To Implement after character class is completed *******<<< . >>>***
	//if(player->getHp > 0): true else{false;}
	return true;
}

Game::~Game(){}