#include<string>
#include <iostream>
#include <fstream>
#include "Thing.h"
#include "Person.h"
using namespace std;

class Weapon : public Thing
{
public:
	float cost;
	string wSound;
	string weaponSound[9] = { "Swish swish" , "Whoosh" , "Pokey poke" , " fwip " , " FWIP " , " fwip " , "Swish swish" , " Whoosh " , " Doooooooom " };
	string weaponNames[9] = { "shortSword" , "longSword" , "spear" , "shortBow" , "longBow" , "crossBow" , "shortSword +1" , "longSword +1" , "Sword of Doom" };
	float weaponCosts[9] = { 10, 10, 15, 35, 35, 50, 110, 110, 250 };
	int weaponDamage[9];
public:
	Weapon(int i)
	{
		cost = weaponCosts[i -1];
		setName(weaponNames[i -1]);
		wSound = weaponSound[i -1];
	}

	void useWeapon(Person* target);
};
