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
