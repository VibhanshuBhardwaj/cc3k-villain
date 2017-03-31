
#include "Floor.h"
#include "Character/Player/PlayerFactory.h"
#include "Character/Enemy/EnemyFactory.h"
#include <cmath>

class Chamber;
class PlayerFactory;
class EnemyFactory;

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
	action = playerRace + " EnTeRs tHe DuNgEoN!";
}

// ENEMY MOVEMENT
bool Floor::enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex){
	//cout << "enemy move called" << endl;
	//cout << "row, col: " << row <<" "<< col<< endl;
	//cout << "can enemy attack" << canEnemyAttackPlayer(enemies[eIndex]) << endl;
	if (canEnemyAttackPlayer(enemies[eIndex])) {enemies[eIndex]->attackPlayer(player); return true;}
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
		//	cout << " x " << x << endl;
		//	cout << " y " << y<< endl;
			int dir = rand() % 8 + 1; //generates random number from 1 to 8
		//	cout << "dir" << dir << endl;
			//cout << grid[y+1][x-1]->isOccupied()<<endl;
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
		action = playerRace + " moves " + dir;
		return true;
	}
	return false;
}

void Floor::atkDirection(string dir) {
	//cout << "inside floor atkDirection with " << dir << endl;
	//cout <<"tryna print player currCell" << player->getCurrCell() << endl;
	Cell* currCell = player->getCurrCell();
	//cout << "after currcell" << endl;
	int x = currCell->getCol();
	int y = currCell->getRow();
	//cout << "x : " << x << "y :" << y << endl;
	//cout << "before ifs" << endl;
	//cout << "character: " << grid[y-1][x]->getCharacter() << endl;
	if (dir == "no") player->attack(grid[y-1][x]->getCharacter());
	else if (dir == "so") player->attack(grid[y+1][x]->getCharacter());
	else if (dir == "ea") player->attack(grid[y][x+1]->getCharacter());
	else if (dir == "we") player->attack(grid[y][x-1]->getCharacter());
	else if (dir == "ne") player->attack(grid[y-1][x+1]->getCharacter());
	else if (dir == "nw") player->attack(grid[y-1][x-1]->getCharacter());
	else if (dir == "se") player->attack(grid[y+1][x+1]->getCharacter());
	else if (dir == "sw") player->attack(grid[y+1][x-1]->getCharacter());
}
void Floor::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw

	//cout <<"player move" << endl;
	Cell* currCell = player->getCurrCell();
	int x = currCell->getCol();
	int y = currCell->getRow();
	//cout <<"before if" << endl;
	//	cout << "inside no" << endl;


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

	//cout << "enemy move" << endl;
	//enemyMove(); //MOVE ENEMIES
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

void Floor::insertCharacter(int x, int y, Character* ch){ //x is left margin, y is Top margin
	//cout << ch->getSymbol() << endl;
	if (ch) grid[y][x]->occupy(ch);

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
		int id = rand() % 5;
		vector<int> pos = getRandPos(id);
		insertSymbol(pos[0], pos[1], 'P');
	}
}

//CREATE AND INSERTS GOLD ON THE GRID
void Floor::spawnGold(){
	for(int i = 0; i < 10; i++){
		int id = rand() % 5;
		vector<int> pos = getRandPos(id);
		insertSymbol(pos[0], pos[1], 'G');
	}
}

void Floor::freezeEnemy(){
	action = "EnEmIeS FrEeZeD! ";
	freeze = true;
}

void Floor::unfreezeEnemy(){
	action = "eNeMiEs aRe FrEe tO MoVe NoW! ";
	freeze = false;
}

//CREATES AND INTERTS ENEMIES ON THE GRID
void Floor::spawnEnemies(){
	for(int i = 0; i < 20; i++){
		EnemyFactory ef = EnemyFactory();
		//int rn = rand() % 18; //generating random enemy
		int id = rand()% 5; //generating random chamber
		vector<int> pos = getRandPos(id);
		Enemy *thisEnemy = ef.generateEnemy(); //factory method call

		insertCharacter(pos[0], pos[1], thisEnemy);
		enemies.emplace_back(thisEnemy);
	}
}

Floor::~Floor(){ //once we have a player pointer, delete it while destructing}
	delete player;
}

//PRINTS LAST 5 LINES OF THE DISPLAY
void Floor::printStats(){
	//cout << "Race: "<<playerRace << " Gold: "<< player->getScore() ;
	cout << "Race: "<<playerRace << " Gold: "<< 0 ; //for now
	for(int i = 0; i< 50; i++){cout << " ";}
	cout <<"Floor " << floorLevel <<endl;
	cout <<"HP: " << player->getHp() << endl;
	cout <<"Atk: "<< player->getAtk() << endl;
	cout <<"Def: "<<player->getDef() << endl;
	//cout << "Action: " << action << endl;
}

string Floor::getAction(){
	return action;
}

void Floor::setAction(string ac){
	action = ac;
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