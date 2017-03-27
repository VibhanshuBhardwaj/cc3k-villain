#include "Cell.h"
#include <string>
#include <iostream>

using namespace std;

Cell::Cell(){
}

Cell::Cell(int row, int col, char sym, std::string type): row{row}, col{col}, symbol{sym}, type{type}, occupied{false}{
}

bool Cell::isOccupied(){
	return occupied;
}


void Cell::occupy(char ch){
	occupied = true;
	whoOccupied = ch;
}

void Cell::leave(){
	occupied = false;
}

char Cell::getSymbol(){
	if(occupied){
		return whoOccupied;
	}
	return symbol;
}

bool Cell::playerMoveValid(){ // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR 
	if((type == "TILE" || type == "PATHWAY" || type == "STAIR" || type == "DOOR") && !isOccupied()){
		return true;
	}
	return false;
}

bool Cell::enemyMoveValid(){
	if(type == "TILE" && !isOccupied()){
		return true;
	}
	return false;
}