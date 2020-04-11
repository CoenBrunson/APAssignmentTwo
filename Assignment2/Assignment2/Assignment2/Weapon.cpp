#include "Weapon.h"

void Weapon::useWeapon(Person* target)
{
	cout << wSound << endl;
	int toHit = rand() % 20 + 1;
	if(toHit >= target->getAC())

}
