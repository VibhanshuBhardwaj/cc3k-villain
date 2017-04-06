#include "Chamber.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
Chamber::Chamber(){}

Chamber::Chamber(int id): id{id}{ 

	if(id == 0){ //top left chamber
		height = 4;
		width = 26;
		upMargin = 3;
		leftMargin = 3;
	}
	else if(id == 1){ // top right chamber
		height = 10;
		width = 37;
		upMargin = 3;
		leftMargin = 39;
	}
	else if(id == 2){ //middle chamber
		height = 3;
		width = 12;
		upMargin = 10;
		leftMargin = 38;
	}
	else if(id == 3){ //bottom left chamber
		height = 7;
		width = 21;
		upMargin = 15;
		leftMargin = 4;
	}
	else{ //bottom right chamber
		height = 6;
		width = 39;
		upMargin = 16;
		leftMargin = 37;
	}

}
/*
bool Chamber::posValid(int x, int y){
	if(map[x][y] == "."){
		return true;
	}
	return false;
}
*/

Chamber::~Chamber(){}

vector<int> Chamber::generateRandPos(){

	int x = rand() % width;
	int y = rand() % height;

	x += leftMargin;
	y += upMargin;

	vector<int> position;
	position.emplace_back(x);
	position.emplace_back(y);
	return position;
}

