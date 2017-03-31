#include "Cell.h"
#include <string>
#include <iostream>

#include "Character/Character.h"

using namespace std;

Cell::Cell(){
}

Cell::Cell(int row, int col, char sym, std::string type): row{row}, col{col}, symbol{sym}, type{type}, occupied{false}{
}

bool Cell::isOccupied(){
	///cout << "is occupied:" << occupied << endl;
	return occupied;
}

Character* Cell::getCharacter() { if (whoOccupied) return whoOccupied; else return nullptr;}
void Cell::occupy(Character* ch){
	//cout << "cell occupied" << endl;
	occupied = true;
	ch->setCurrCell(this); //player should 'have a' cell
	whoOccupied = ch;
}

void Cell::leave(){
	occupied = false;
	whoOccupied =  nullptr; //nobody's occupying that cell now
}

bool Cell::atStairs(){
	if(symbol == '/'){
		return true;
	}
	return false;
}

char Cell::getSymbol(){
	if(occupied){
		return whoOccupied->getSymbol();
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
	//cout << "inside cell" << endl;
	if(type == "TILE" && !isOccupied()){
		return true;
	}
	return false;
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

void Cell::setSymbol(char ch) { symbol = ch; }
