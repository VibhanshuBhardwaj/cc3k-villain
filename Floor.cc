
#include "Floor.h"
#include "Character/Player/PlayerFactory.h"
#include "Character/Enemy/EnemyFactory.h"
#include "Item/Potion/PotionFactory.h"
#include "Item/Gold/GoldFactory.h"
#include <cmath>

class Chamber;
class PlayerFactory;
class EnemyFactory;
class GoldFactory;

using namespace std;


Floor::Floor(string file, string pRace, int fLevel){
	playerRace = pRace;
	floorLevel = fLevel;
	string line;
	//cout << file << endl;
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
	freeze = false;
	//initialize chambers
	for(int i = 0; i < 5; i ++){
		chambers[i] = Chamber(i);
	}

	//spawn all characters and items randomly on the floor
	//cout << "before spawn player" << endl;
	spawnPlayer();
	spawnStairs();
	spawnPotions();
	spawnGold();
	spawnEnemies();
	action = playerRace + " EnTeRs tHe DuNgEoN! ";
}

// CREATE PLAYER CHARACTER AND SPAWNS ON THE GRID
void Floor::spawnPlayer(){
	//after character class is completely initialized,
	//we will have a pointer to player character
	int id = rand() % 5; //generates random number between 0 to 5.
	PlayerFactory pf = PlayerFactory();
	vector<int> pos = getRandPos(id);
	player = pf.generatePlayer(playerRace);
	insertCharacter(pos[0], pos[1], player); //playerrace is a string/character. will be replaced with 'player character'
	playerSpawnedChamber = id;
}

//CREATES AND INSERT STAIR ON THE GRID
void Floor::spawnStairs(){
	int id = rand() % 5;
	while(id == playerSpawnedChamber){
		id = rand() % 5;
	}
	vector<int> pos = getRandPos(id);
	insertSymbol(pos[0], pos[1], '/');
}

//CREATE AND INSERTS POTIONS ON THE GRID
void Floor::spawnPotions(){
	for(int i = 0; i < 10; i++){
		PotionFactory potFac = PotionFactory(); 
		int id = rand() % 5; 
		vector<int> pos = getRandPos(id);
		Potion *thisPotion = potFac.generatePotion();
		insertPotion(pos[0], pos[1], thisPotion);
		potions.emplace_back(thisPotion);
	}
}

//CREATE AND INSERTS GOLD ON THE GRID
void Floor::spawnGold(){
	for(int i = 0; i < 10; i++){
		GoldFactory goldFac = GoldFactory();
		int id = rand() % 5;
		vector<int> pos = getRandPos(id);
		Gold *thisGold = goldFac.generateGold();
		insertGold(pos[0], pos[1], thisGold);
		golds.emplace_back(thisGold);
	}
}

//CREATES AND INTERTS ENEMIES ON THE GRID
void Floor::spawnEnemies(){
	for(int i = 0; i < 20; i++){
		EnemyFactory ef = EnemyFactory();
		int id = rand()% 5; //generating random chamber
		vector<int> pos = getRandPos(id);
		Enemy *thisEnemy = ef.generateEnemy(); //factory method call
		insertCharacter(pos[0], pos[1], thisEnemy);
		enemies.emplace_back(thisEnemy);
	}
}

// ENEMY MOVEMENT
bool Floor::enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex){ //rename this to sth more appropriate
	//cout << "enemy move called" << endl;
	//cout << "row, col: " << row <<" "<< col<< endl;
	//cout << "can enemy attack" << canEnemyAttackPlayer(enemies[eIndex]) << endl;
	if (canEnemyAttackPlayer(enemies[eIndex])) {
		int i = rand() % 2;
		//cout << "i: " << i << endl;
		if (i) enemies[eIndex]->attackPlayer(player);
		else{
			cout << "Enemy missed its attack! REMOVE THIS STATEMENT" << endl;
		}
		return true;
	}
	if(grid[row][col]->enemyMoveValid()){
	//	cout << "inside enemy moved if" << endl;
		grid[row][col]->occupy(enemies[eIndex]);
		enemies[eIndex]->setCurrCell(grid[row][col]);
		grid[prevRow][prevCol]->leave();
	//	cout << "ret true" << endl;
		return true;
	}
	//cout << "ret false" << endl;
	return false;
}

bool Floor::canEnemyAttackPlayer(Enemy* enemy) {
	//distance formula between 2 points. checks if player is within attack range
	return pow((enemy->getCurrCell()->getRow() - player->getCurrCell()->getRow()), 2) + pow((enemy->getCurrCell()->getCol() - player->getCurrCell()->getCol()), 2) <= 2;
}

void Floor::enemyMove(){
	for(int i = 0; i < 20; i++){
	//	cout << "ith enemy sym: " << enemies[i]->getSymbol() << endl;
		if(enemies[i]->isAlive()){
			//cout << "can enemy attack" << canEnemyAttackPlayer(enemies[i]) << endl;
			Cell* currCell = enemies[i]->getCurrCell();
			int x = currCell->getCol();
			int y = currCell->getRow();
			int dir = rand() % 8 + 1; //generates random number from 1 to 8
			if(grid[y-1][x]->isOccupied() && grid[y+1][x]->isOccupied() && grid[y][x+1]->isOccupied() && grid[y][x-1]->isOccupied() && grid[y-1][x+1]->isOccupied() && grid[y-1][x-1]->isOccupied() && grid[y+1][x+1]->isOccupied() && grid[y+1][x-1]->isOccupied()){
			//	cout << "first if" << endl;
				continue;
			}
			else if(dir == 1){//NORTH
				if(!enemyMoved(y-1, x, y, x, i)){i--;}
			}
			else if(dir == 2){//SOUTH
				if(!enemyMoved(y+1, x, y, x, i)){i--;}
			}
			else if(dir == 3){//EAST
				if(!enemyMoved(y, x+1, y, x, i)){ i--;	}
			}
			else if(dir == 4){//WEST
				if(!enemyMoved(y, x-1, y, x, i)){ i--; }
			}
			else if(dir == 5){//NORTH-EAST
				if(!enemyMoved(y-1, x+1, y, x, i)){i--;}
			}
			else if(dir == 6){//NORTH-WEST
				if(!enemyMoved(y-1, x-1, y, x, i)){i--;}
			}
			else if(dir == 7){//SOUTH-EAST
				if(!enemyMoved(y+1, x+1, y, x, i)){i--;}
			}
			else{ //SOUTH-WEST
				//cout << "else block" << endl;
				//cout << enemies[i]->getSymbol() << endl;
				if(!enemyMoved(y+1, x-1, y, x, i)){ i--;}
			}
		}
	}
	//cout <<"end enemyMove" << endl;
}

//PLAYER MOVEMENT
bool Floor::playerMoved(int row, int col, int prevRow, int prevCol, string dir){
	if(grid[row][col]->playerMoveValid()){
		grid[row][col]->occupy(player);
		player->setCurrCell(grid[row][col]);
		grid[prevRow][prevCol]->leave();
		action = playerRace + " moves " + dir + ".";
		return true;
	}
	else if(grid[row][col]->isGold()){
		Item *g = grid[row][col]->getItem();
		g->use(player);
		action = playerRace + " collects "+g->getType() +". ";
		grid[row][col]->leave();
		grid[row][col]->occupy(player);
		player->setCurrCell(grid[row][col]);
		grid[prevRow][prevCol]->leave();
		return true;
	}
	return false;
}

//ATTACK DIRECTION
void Floor::atkDirection(string dir) {
	Cell* currCell = player->getCurrCell();
	int x = currCell->getCol();
	int y = currCell->getRow();
	if (dir == "no") player->attack(grid[y-1][x]->getCharacter());
	else if (dir == "so") player->attack(grid[y+1][x]->getCharacter());
	else if (dir == "ea") player->attack(grid[y][x+1]->getCharacter());
	else if (dir == "we") player->attack(grid[y][x-1]->getCharacter());
	else if (dir == "ne") player->attack(grid[y-1][x+1]->getCharacter());
	else if (dir == "nw") player->attack(grid[y-1][x-1]->getCharacter());
	else if (dir == "se") player->attack(grid[y+1][x+1]->getCharacter());
	else if (dir == "sw") player->attack(grid[y+1][x-1]->getCharacter());
	
	if(!freeze){ //Always runs
		enemyMove(); //MOVE ENEMIES
	}
}


//POTION NEIGHBOUR
bool Floor::isPotion(int x, int y){
	return grid[y][x]->isPotion();
	cout <<"done" << endl;
}

void Floor::checkPotion(){
	Cell* currCell = player->getCurrCell();
	int x = currCell->getCol();
	int y = currCell->getRow();
	Item *p = nullptr;
	if(isPotion(x, y-1)) p = grid[y-1][x]->getItem(); 
	else if(isPotion(x, y+1)) p = grid[y+1][x]->getItem();
	else if(isPotion(x-1, y)) p = grid[y][x-1]->getItem();
	else if(isPotion(x+1, y)) p = grid[y][x+1]->getItem();
	else if(isPotion(x+1, y-1)) p = grid[y-1][x+1]->getItem();
	else if(isPotion(x-1, y-1)) p = grid[y-1][x-1]->getItem();
	else if(isPotion(x+1, y+1)) p = grid[y+1][x+1]->getItem();
	else if(isPotion(x-1, y+1)) p = grid[y+1][x-1]->getItem();
	
	if(p){ //P IS A POTION
		if(p->getVisited()) action += " Sees a Potion of Type: "+ p->getType() +".";
		if(!p->getVisited()) action += " Sees a Potion of Unknown Type. " ;
	}
}


//USE POTION
void Floor::usePotion(string dir){
	Cell* currCell = player->getCurrCell();
	int x = currCell->getCol();
	int y = currCell->getRow();
	string result = "";
	if (dir == "no") result = player->usePotion(grid[y-1][x]->getItem());
	else if (dir == "so") result = player->usePotion(grid[y+1][x]->getItem());
	else if (dir == "ea") result = player->usePotion(grid[y][x+1]->getItem());
	else if (dir == "we") result = player->usePotion(grid[y][x-1]->getItem());
	else if (dir == "ne") result = player->usePotion(grid[y-1][x+1]->getItem());
	else if (dir == "nw") result = player->usePotion(grid[y-1][x-1]->getItem());
	else if (dir == "se") result = player->usePotion(grid[y+1][x+1]->getItem());
	else if (dir == "sw") result = player->usePotion(grid[y+1][x-1]->getItem());

	if(result == "") action += "No Potion Found in "+ dir + " direction.";
	if(result != "") action += result;
	if(!freeze){ //Always runs
		enemyMove(); //MOVE ENEMIES
	}

}

//PLAYER MOVEMENT
bool Floor::playerMoved(int row, int col, int prevRow, int prevCol, string dir){
	if(grid[row][col]->playerMoveValid()){
		grid[row][col]->occupy(player);
		player->setCurrCell(grid[row][col]);
		grid[prevRow][prevCol]->leave();
		action = playerRace + " moves " + dir + ".";
		return true;
	}
	else if(grid[row][col]->isGold()){
		Item *g = grid[row][col]->getItem();
		g->use(player);
		action = playerRace + " collects "+g->getType() +". ";
		grid[row][col]->leave();
		grid[row][col]->occupy(player);
		player->setCurrCell(grid[row][col]);
		grid[prevRow][prevCol]->leave();
		return true;
	}
	return false;
}

void Floor::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw
	Cell* currCell = player->getCurrCell();
	int x = currCell->getCol();
	int y = currCell->getRow();

	if(dir == "no" && !playerMoved(y-1, x, y, x, "North")){ //NORTH
		action = "Cannot move there! " ;
	}
	else if(dir == "so" && !playerMoved(y+1, x, y, x, "South")){ //SOUTH
		action = "Cannot move there! " ;
	}
	else if(dir == "ea" && !playerMoved(y, x+1, y, x, "East")){ //EAST
		action = "Cannot move there! " ;
	}
	else if(dir == "we" && !playerMoved(y, x-1, y, x, "West")){ //WEST
		action = "Cannot move there! " ;
	}
	else if(dir == "ne" && !playerMoved(y-1, x+1, y, x, "North-East")){ //NORTH-EAST
		action = "Cannot move there! " ;
	}
	else if(dir == "nw" && !playerMoved(y-1, x-1, y, x, "North-West")){ //NORTH-WEST
		action = "Cannot move there! " ;
	}
	else if(dir == "se" && !playerMoved(y+1, x+1, y, x, "South-East")){ //SOUTH-EAST
		action = "Cannot move there! " ;
	}
	else if(dir == "sw" && !playerMoved(y+1, x-1, y, x, "South-West")){ //SOUTH-WEST
		action = "Cannot move there! " ;
	}

	if(!freeze){ //Always runs
		enemyMove(); //MOVE ENEMIES
	}
	checkPotion();
}

//TRUE IF THE PLAYER HAS REACHED THE STAIRS
bool Floor::atStairs(){
	Cell* currCell = player->getCurrCell();
	if(currCell->atStairs()){
		return true;
	}
	return false;
}

void Floor::insertSymbol(int x, int y, char ch){ //x is left margin, y is Top margin
	grid[y][x]->setSymbol(ch);
}

void Floor::insertPotion(int x, int y, Potion * p){
	if(p) grid[y][x]->occupy(p);
}

void Floor::insertGold(int x, int y, Gold * g){
	if(g) grid[y][x]->occupy(g);
}


void Floor::insertCharacter(int x, int y, Character* ch){ //x is left margin, y is Top margin
	//cout << ch->getSymbol() << endl;
	if (ch && ch->isAlive()) grid[y][x]->occupy(ch);
	//else if (!ch->isAlive()) {cout << "enemy died" << endl; grid[y][x]->leave(); insertSymbol(x, y, 'G'); }//maybe add the dropped gold here
}


// CHECKS IF A CHARACTER OR AN ITEM CAN BE SPAWNED AT (X, Y) ON GRID
bool Floor::isValid(int x, int y){ //y is row and x is column
	if(grid[y][x]->getSymbol() == '.'){
		return true;
	}
	return false;
}

//GENERATES A RANDOM VALID POSITION
vector<int> Floor::getRandPos(int chamberId){      
	vector<int> pos = chambers[chamberId].generateRandPos();
	int x = pos[0];
	int y = pos[1];
	if(isValid(x, y)){
		return pos;
	}
	return getRandPos(chamberId);
}


void Floor::freezeEnemy(){
	action = "EnEmIeS FrEeZeD! ";
	freeze = true;
}

void Floor::unfreezeEnemy(){
	action = "eNeMiEs aRe FrEe tO MoVe NoW! ";
	freeze = false;
}



Floor::~Floor(){ //once we have a player pointer, delete it while destructing}
	delete player;
}


//PRINTS LAST 5 LINES OF THE DISPLAY
void Floor::printStats(){
	//cout << "Race: "<<playerRace << " Gold: "<< player->getScore() ;
	cout << "Race: "<<playerRace << " Gold: "<< player->getScore() ; //for now
	for(int i = 0; i< 50; i++){cout << " ";}
	cout <<"Floor " << floorLevel <<endl;
	cout <<"HP: " << player->getHp() << endl;
	cout <<"Atk: "<< player->getAtk() << endl;
	cout <<"Def: "<<player->getDef() << endl;
//	cout << "Action: " << player->getAction() << endl;
}

string Floor::getAction(){
	return action + player->getAction();
}

void Floor::setAction(string ac){
	action = "";
	player->setAction(ac);
}


//PRINTS THE GRID
void Floor::printFloor(){
	for(int i = 0; i < 25; i++ ){
		for(int j = 0; j < 79; j++){
			cout << grid[i][j]->getSymbol() ;
		}
		cout << endl;
	}
}

bool Floor::isPlayerAlive() {
	return player->getHp() > 0;
}