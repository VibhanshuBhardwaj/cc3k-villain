#include "EnemyFactory.h"

#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
#include "Human.h"
#include "Orc.h"
#include "Merchant.h"
#include <string>


#include <stdexcept>

using namespace std;

Enemy* EnemyFactory::generateEnemy() {
	Enemy *thisEnemy;
	int rn = rand() % 18;
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
	else{
		//cout << "generating merchant" << endl;
		thisEnemy = new Merchant(); //merchant
	}
	return thisEnemy;

}