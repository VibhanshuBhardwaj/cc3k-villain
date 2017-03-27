
#include "Floor.h"

class Chamber;
class Player;

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

bool Floor::enemyMoved(int row, int col, int prevRow, int prevCol, int eIndex){
	if(grid[row][col]->enemyMoveValid()){
		grid[row][col]->occupy(enemies[eIndex]->getSymbol());
		enemies[eIndex]->posUpdate(row, col);
		grid[prevRow][prevCol]->leave();
		return true;
	}
	return false;
}

void Floor::enemyMove(){
	for(int i = 0; i < 20; i++){
		if(enemies[i]->isAlive()){
			vector<int> enemyPos = enemies[i]->getPos();
			int x = enemyPos[0];
			int y = enemyPos[1];
			int dir = rand() % 8 + 1; //generates random number from 1 to 8 
			if(grid[y-1][x]->isOccupied() && grid[y+1][x]->isOccupied() && grid[y][x+1]->isOccupied() && grid[y][x-1]->isOccupied() && grid[y-1][x+1]->isOccupied() && grid[y-1][x-1]->isOccupied() && grid[y+1][x+1]->isOccupied() && grid[y+1][x-1]->isOccupied()){
				continue;
			} 
			else if(dir == 1){//NORTH 
				if(!enemyMoved(y-1, x, y, x, i)){	i--;}
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
				if(!enemyMoved(y+1, x-1, y, x, i)){i--;}
			}
		}
	}
}

bool Floor::playerMoved(int row, int col, int prevRow, int prevCol){
	if(grid[row][col]->playerMoveValid()){
		grid[row][col]->occupy('@');
		player->posUpdate(row, col);
		grid[prevRow][prevCol]->leave();
		return true;
	}
	return false;
}

void Floor::playerMove(string dir){ //no ,so, ea, we, ne, nw, se, sw
	vector<int> playerPos = player->getPos();
	int x = playerPos[0];
	int y = playerPos[1];

	if(dir == "no" && !playerMoved(y-1, x, y, x)){
		action = "Cannot move there! " ;
	}
	else if(dir == "so" && !playerMoved(y+1, x, y, x)){
		action = "Cannot move there! " ;
	}
	else if(dir == "ea" && !playerMoved(y, x+1, y, x)){
		action = "Cannot move there! " ;
	}
	else if(dir == "we" && !playerMoved(y, x-1, y, x)){
		action = "Cannot move there! " ;
	}
	else if(dir == "ne" && !playerMoved(y-1, x+1, y, x)){ //NORTH-EAST
		action = "Cannot move there! " ;
	}
	else if(dir == "nw" && !playerMoved(y-1, x-1, y, x)){ //NORTH-WEST
		action = "Cannot move there! " ;
	}
	else if(dir == "se" && !playerMoved(y+1, x+1, y, x)){ //SOUTH-EAST
		action = "Cannot move there! " ;
	}
	else if(dir == "sw" && !playerMoved(y+1, x-1, y, x)){ //SOUTH-WEST
		action = "Cannot move there! " ;
	}
	else{
		action = "Cannot move there! " ;
	}
	enemyMove(); //MOVE ENEMIES
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
	player = new Player(pos[1], pos[0]);
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
		Enemy *thisEnemy;
		if(rn >= 1 && rn <= 4){
			insert(pos[0], pos[1], 'H'); //Human
			thisEnemy = new Enemy(pos[1], pos[0], 'H');
		}
		else if(rn >= 5 && rn <= 7){
			insert(pos[0], pos[1], 'W'); //Dwarf
			thisEnemy = new Enemy(pos[1], pos[0], 'W');
		}
		else if(rn >= 8 && rn <= 12){
			insert(pos[0], pos[1], 'L'); //HalfLing
			thisEnemy = new Enemy(pos[1], pos[0], 'L');
		}
		else if(rn >= 13 && rn <= 14){
			insert(pos[0], pos[1], 'E'); //Elf
			thisEnemy = new Enemy(pos[1], pos[0], 'E');
		}
		else if(rn >= 15 && rn <= 16){
			insert(pos[0], pos[1], 'O'); //orc
			thisEnemy = new Enemy(pos[1], pos[0], 'O');
		}
		else{
			insert(pos[0], pos[1], 'M'); //Merchant
			thisEnemy = new Enemy(pos[1], pos[0], 'M');
		}
		enemies.emplace_back(thisEnemy);
	}
}

Floor::~Floor(){ //once we have a player pointer, delete it while destructing}
	delete player;
}

void Floor::printFloor(){
	for(int i = 0; i < 25; i++ ){
		for(int j = 0; j < 79; j++){
			cout << grid[i][j]->getSymbol() ;
		}
		cout << endl;
	}
}