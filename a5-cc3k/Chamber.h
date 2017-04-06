#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <vector>
#include <string>
#include <iostream>

class Floor;

class Chamber{
	int id;
	int height;
	int width;
	//std::string *map[25];
	int upMargin; //number of rows above
	int leftMargin; //number of columns on the left
	bool isValid();

  public:
  	Chamber();
	Chamber(int id); //taking reference of map 
	std::vector<int> generateRandPos();
	//bool posValid(int x, int y);
	~Chamber();

};

#endif
