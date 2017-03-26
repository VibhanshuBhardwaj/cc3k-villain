#include "Game.h"
#include "Floor.h"
#include <string>
#include <iostream>
using namespace std;

//class Floor;
//class Chamber;
Game::Game(){}

Game::Game(string playerRace, string fileName): playerRace{playerRace}, fileName{fileName}{ //initialize a new game 
	floorLevel = 0; //
	//cout <<"Game ctor" <<endl;
	floor = new Floor(fileName, playerRace); //(fileName, replace with player*) 
}

void Game::printGame(){
	floor->printFloor();
}
/*
void Game::playerMove(string dir){
	floor->playerMove(dir);

void Game::usePotion(string dir){
	floor->usePotion(dir);
}

void Game::atkDirection(string dir){
	floor->atkDirection(dir);
}

void Game::freezeEnemy(){
	floor->freezeEnemy();
}

void Game::unfreezeEnemy(){
	floor->unfreezeEnemy();
}
*/
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


