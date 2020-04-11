#ifndef __PERSON__
#define __PERSON__

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
private:
	string name;
	int health;
	string type[4] = { "Innkeeper", "Blacksmith", "Merchant", "Questline" };
	string currentType;
	int AC;
	string line;
public:
	Person(string n, int t);
	~Person() {};
	void setName(string n) { name = n; };
	string getName() { return name; }
	void setHealth(int h) { health = h; };
	int getHealth() { return health; };
	void setType(int t) { currentType = type[t]; };
	string getCurrentType() { return currentType; };
	int getAC() { return AC; };
	void setAC(int ac) { AC = ac; };
	string getLine();
};
#endif