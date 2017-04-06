#include "EnemyFactory.h"

#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
#include "Human.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Vib.h"
#include <string>


#include <stdexcept>

using namespace std;

Enemy* EnemyFactory::generateEnemy() {
	Enemy *thisEnemy;
	int rn = (rand() % 19) + 1;
	if(rn >= 1 && rn <= 4){
		//cout << "generating human" << endl;
		thisEnemy = new Human();
	}
	else if(rn >= 5 && rn <= 7){
		//cout << "generating dawrf" << endl;
		thisEnemy = new Dwarf();
	}
	else if(rn >= 8 && rn <= 12){
		//cout << "generating halfling" << endl;
		thisEnemy = new Halfling();
	}
	else if(rn >= 13 && rn <= 14){
		//cout << "generating elf" << endl;
		thisEnemy = new Elf();
	}
	else if(rn >= 15 && rn <= 16){
		//cout << "generating orc" << endl;
		thisEnemy = new Orc();
	}
	else if(rn >= 17 && rn <= 18){
		//cout << "generating merchant" << endl;
		thisEnemy = new Merchant(); //merchant

	}
	else {
		thisEnemy =  new Vib(); //muawhahahahaha
	}
	return thisEnemy;

}

Enemy* EnemyFactory::generateEnemy(char e) {
	Enemy *thisEnemy;
	if(e == 'H'){
		//cout << "generating human" << endl;
		thisEnemy = new Human();
	}
	else if(e == 'W'){
		//cout << "generating dawrf" << endl;
		thisEnemy = new Dwarf();
	}
	else if(e == 'L'){
		//cout << "generating halfling" << endl;
		thisEnemy = new Halfling();
	}
	else if(e == 'E'){
		//cout << "generating elf" << endl;
		thisEnemy = new Elf();
	}
	else if(e == 'O'){
		//cout << "generating orc" << endl;
		thisEnemy = new Orc();
	}
	else if(e == 'M'){
		thisEnemy = new Merchant(); //merchant
	}
	else if(e == 'D'){//DRAGON
		thisEnemy = new Dragon();
	}
	else if (e == 'V') {//Vib
		thisEnemy = new Vib();
	}
	return thisEnemy;

}
