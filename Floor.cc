#include "Floor.h"
#include <string>
#include <vector> 
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "Chamber.h"
#include <ctime>
#include "Cell.h"

class Chamber;

using namespace std;


Floor::Floor(string file, string pRace){
	playerRace = pRace;
	string line;
	ifstream infile(file);
	if(!infile){
		cout<< "cannot open the given file."<< endl;
	}

	for(int i = 0; i < 25; i++){
		getline(infile, line);
		vector<Cell*> row;
		for(int j = 0; j < 79; j++){
			if(line[j] == '|'){
				row.emplace_back(new Cell(i, j, '|', "VWALL"));
			}
			else if(line[j] == '-'){
				row.emplace_back(new Cell(i, j, '-', "HWALL"));
			}
			else if(line[j] == '.'){
				row.emplace_back(new Cell(i, j, '.', "TILE"));
			}
			else if(line[j] == '+'){
				row.emplace_back(new Cell(i, j, '+', "DOOR"));
			}
			else if(line[j] == '#'){
				row.emplace_back(new Cell(i, j, '#', "PATHWAY"));
			}
			else{ //emplty space
				row.emplace_back(new Cell(i, j, ' ', "SPACE"));
			}
		}
		grid.emplace_back(row);
	}

	//initialize chambers
	for(int i = 0; i < 5; i ++){
		chambers[i] = Chamber(i);
	}

	//spawn all characters and items randomly on the floor
	spawnPlayer();
	spawnStairs();
	spawnPotions();
	spawnGold();
	spawnEnemies();
}

void Floor::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw

}


void Floor::insert(int x, int y, char ch){ //x is left margin, y is Top margin
	grid[y][x]->occupy(ch);
}


bool Floor::isValid(int x, int y){ //y is row and x is column 
	if(grid[y][x]->getSymbol() == '.'){
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
		for(int j = 0; j < 79; j++){
			cout << grid[i][j]->getSymbol() ;
		}
		cout << endl;
	}
}