#include<iostream>
#include<string>
#include<fstream>
#include"Person.h"

class Enemy : public Person
{
private:
	int AP;
	string species;
public:
	Enemy(int species);
	~Enemy() {};
	int getAP() { return AP; };
	void setSpecies(string s) { species = s; };
};
