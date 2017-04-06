#include "Item.h"

using namespace std;

Item::Item(){}

Item::Item(string type): type{type}{}

Cell * Item::getCurrCell(){
	return currCell;
}

void Item::setCurrCell(Cell *newCell){
	currCell = newCell;
}

string Item::getType(){
	return type;
}

Item::~Item(){}

