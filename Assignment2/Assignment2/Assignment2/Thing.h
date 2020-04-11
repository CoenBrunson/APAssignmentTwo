#ifndef __THING__
#define __THING__
#include<iostream>
#include<string>
using namespace std;

class Thing
{
private:
	string name;
public:
	void setName(string n) { name = n; };
	string getName() { return name; };
};
#endif // !__THING__
