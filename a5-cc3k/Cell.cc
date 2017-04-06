#include "Cell.h"
#include <string>
#include <iostream>

#include "Character/Character.h"

using namespace std;

Cell::Cell(){
}

Cell::Cell(int row, int col, char sym, std::string type): row{row}, col{col}, symbol{sym}, type{type}, occupied{false}{
	whoOccupied = nullptr;
	it = nullptr;
	dragonHoard = false;
}

bool Cell::isOccupied(){
	///cout << "is occupied:" << occupied << endl;
	return occupied;
}

void Cell::occupy(Character* ch){
	//cout << "cell occupied" << endl;
	occupied = true;
	ch->setCurrCell(this); //cell should 'have a' character
	whoOccupied = ch;
}

void Cell::occupy(Item *itm){
	occupied = true;
	itm->setCurrCell(this);
	it = itm;
	if(!itm->isAvailable()){
		//a DRAGON HOARD
		dragonHoard = true;
	}
}

Character* Cell::getCharacter() { if (whoOccupied) return whoOccupied; else return nullptr;}

Item *Cell::getItem() { 
	if(it) {
		
		return it;
	}
	 else return nullptr;}

void Cell::leave(){
	occupied = false;
	whoOccupied = nullptr;
	if(!dragonHoard){
		it = nullptr;
	}
	if(dragonHoard){
		occupied = true;
	}
}

bool Cell::isPotion(){
	if(it){
		if(it->getType()=="PH" || it->getType()=="RH"||it->getType()=="BA" ||it->getType()=="BD"||it->getType()=="WD"||it->getType()=="WA"){
			return  true;
		}
	}
	return false;
}

bool Cell::isGold(){
	if(it){
		if(!isPotion()) return true;
	}
	return false;
}

bool Cell::atStairs(){
	if(symbol == '/'){
		return true;
	}
	return false;
}

char Cell::getSymbol(){
	if(occupied){
		if(whoOccupied){
			return whoOccupied->getSymbol();
		}
		if(it){
			//ITEM
			return it->getSymbol();		
		}
	}
	return symbol;
}

bool Cell::playerMoveValid(){ // TILE / PATHWAY / STAIR / HWALL / VWALL / DOOR
	if((type == "TILE" || type == "PATHWAY" || type == "STAIR" || type == "DOOR") && !isOccupied()){
		//isOccupied()!
		return true;
	}
	return false;
}

bool Cell::enemyMoveValid(){
	//cout << "inside cell" << endl;
	if(type == "TILE" && symbol != '/' && !isOccupied()){
		return true;
	}
	return false;
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }

void Cell::setSymbol(char ch) { symbol = ch; }

