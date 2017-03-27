#include "Floor.h"
#include <string>
#include <vector> 
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Chamber.h"
#include <ctime>

class Chamber;

using namespace std;


Floor::Floor(string file, string pRace){
	playerRace = pRace;
	string row;
	ifstream infile(file);
	if(!infile){
		cout<< "cannot open the given file."<< endl;
	}

	for(int i = 0; i < 25; i++){
		getline(infile, row);
		//cout << row << endl;
		maps[i] = row;
		
		//cout << maps[i] << endl;
		
		row = "";
	}

	//initialize chambers
	for(int i = 0; i < 5; i ++){
		chambers[i] = Chamber(i);
	}

	//spawn all characters and items randomly on the floor randomly
	spawnPlayer();
	spawnStairs();
	spawnPotions();
	spawnGold();
	spawnEnemies();
}

void Floor::insert(int x, int y, char ch){

	//cout << "inserting "<< "x "<< x << " y " << y <<endl;
	maps[y][x] = ch;
}

bool Floor::isValid(int x, int y){ //y is row and x is column 

	if(maps[y][x] == '.'){
		return true;
	}

	return false;
}

vector<int> Floor::getRandPos(int chamberId){

	vector<int> pos = chambers[chamberId].generateRandPos();
	int x = pos[0];
	int y = pos[1];

	if(isValid(x, y)){ 
		return pos;
	}
	return getRandPos(chamberId);
}

void Floor::spawnPlayer(){
	//after character class is completely initialized, 
	//we will have a pointer to player character
	int id = rand() % 5; //generates random number between 0 to 5. 
	vector<int> pos = getRandPos(id);
	insert(pos[0], pos[1], '@'); //playerrace is a string/character. will be replaced with 'player character'
}

void Floor::spawnStairs(){
	int id = rand() % 5;
	vector<int> pos = getRandPos(id);
	insert(pos[0], pos[1], '/');
}

void Floor::spawnPotions(){

	for(int i = 0; i < 10; i++){
		int id = rand() % 5;
		vector<int> pos = getRandPos(id);
		insert(pos[0], pos[1], 'P');
	}
}

void Floor::spawnGold(){

	for(int i = 0; i < 10; i++){
		int id = rand() % 5;
		vector<int> pos = getRandPos(id);
		insert(pos[0], pos[1], 'G');
	}
}

void Floor::spawnEnemies(){

	for(int i = 0; i < 20; i++){
		int rn = rand() % 18; //generating random enemy
		int id = rand()% 5; //generating random chamber 
		vector<int> pos = getRandPos(id);
		if(rn >= 1 && rn <= 4){
			insert(pos[0], pos[1], 'H'); //Human
		}
		else if(rn >= 5 && rn <= 7){
			insert(pos[0], pos[1], 'W'); //Dwarf
		}
		else if(rn >= 8 && rn <= 12){
			insert(pos[0], pos[1], 'L'); //HalfLing
		}
		else if(rn >= 13 && rn <= 14){
			insert(pos[0], pos[1], 'E'); //Elf
		}
		else if(rn >= 15 && rn <= 16){
			insert(pos[0], pos[1], 'O'); //orc
		}
		else{
			insert(pos[0], pos[1], 'M'); //Merchant
		}
	}
}

Floor::~Floor(){ //once we have a player pointer, delete it while destructing}
}

void Floor::printFloor(){
	for(int i = 0; i < 25; i++ ){
		cout << maps[i] << endl;
	}
}