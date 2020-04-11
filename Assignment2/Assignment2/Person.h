#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
private:
	string name;
	int health;
public:
	virtual void setName(string n) = 0;
	virtual string getName() { return name; }
	virtual void setHealth(int h) = 0;
	virtual int getHealth() { return health; };
};