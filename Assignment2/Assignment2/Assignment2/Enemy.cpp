#include "Enemy.h"

Enemy::Enemy(int species)
{
	switch (species) {
	case 1:
		setSpecies("Orc");
		setAC(14);
		AP = 6;
		break;
	case 2:
		setSpecies("Goblin");
		setAC(11);
		AP = 8;
		break;
	case 3:
		setSpecies("Giant");
		setAC(18);
		AP = 10;
		break;
	}
}