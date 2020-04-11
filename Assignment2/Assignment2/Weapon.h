#include<string>
#include <iostream>
#include "Thing.h"
using namespace std;

class Weapon : public Thing
{
public:
	float cost;
	string wSound;
public:
	Weapon(float i, string a, string b)
	{
		cost = i;
		setName(a);
		wSound = b;
	}
};
