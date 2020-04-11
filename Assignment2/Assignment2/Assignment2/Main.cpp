#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<vector>
#include "Weapon.h"
#include "Enemy.h"
#include "Person.h"
#include "Thing.h"
using namespace std;



const int weapons = 9;
int money = 250;
int userSelect = 8;
bool inStore = true;
bool hasWeapon[weapons];
int leaveStore;
int adventureMore;
bool inGame = true;
vector<Weapon*> weaponVec;
vector<Enemy*> enemyVec;
vector<Thing*> thingVec;
vector<Person*> npcVec;

const int width = 32;
const int height = 24;
int mapGrid[width][height];
bool currentTile[width][height];
int currentX, currentY;

void setCurrentTile(int x, int y)
{
	currentTile[currentX][currentY] = false;
	currentX = x;
	currentY = y;
	currentTile[x][y] = true;
}

bool getCurrentTile()
{
	return mapGrid[currentX][currentY];
}

void moveDirection(int d) //outside exploration
{
	switch (d) {
	case 0: //north
		setCurrentTile(currentX, currentY - 1);
		getCurrentTile();
	case 1: //east
		setCurrentTile(currentX + 1, currentY);
		getCurrentTile();
	case 2: //south
		setCurrentTile(currentX, currentY + 1);
		getCurrentTile();
	case 3: //west
		setCurrentTile(currentX - 1, currentY);
		getCurrentTile();
	}
}

void runStore()
{
	for (int i = 0; i < weapons; i++)
	{
		hasWeapon[i] = false;
	}

	do {

		do {

			cout << "Khajiit has wares, if you have coin." << endl;

			for (int i = 0; i < weapons; i++)
			{
				if (hasWeapon[i] == false)
					cout << weaponNames[i] << " [ ]" << endl;
				else
					cout << weaponNames[i] << "[X]" << endl;
			}

			cout << endl << "Current money: " << money << endl;

			bool purchaseValid = false;
			do {


				int moneyAfter = money;

				cout << "Do you seek to make a purchase?: ";

				bool userInput = false;
				do {

					cin >> userSelect;
					if (userSelect <= 9 || userSelect >= 1)
					{
						userInput = true;
					}
					else {
						cout << "Sorry, I didn't catch that.  Could you try again?" << endl << endl;
					}
				} while (userInput == false);

				moneyAfter -= weaponCosts[userSelect - 1];

				if (moneyAfter < 0 || hasWeapon[userSelect - 1] == true) {
					cin.clear();
					cin.ignore();
					cout << "Khajiit has the wares, but do you have the gold? Try again." << endl << endl;
				}
				else
				{
					purchaseValid = true;
				}

			} while (purchaseValid == false);

			cout << "Thanks for buying my " << weaponNames[userSelect - 1] << " my friend." << endl << endl;

			hasWeapon[userSelect - 1] = true;
			weaponVec.push_back(new Weapon(weaponCosts[userSelect - 1], weaponNames[userSelect - 1], weaponSound[userSelect - 1]));
			money -= weaponCosts[userSelect - 1];

			cout << "Would you like to make another purchase? (0 for yes, anything else for no)" << endl;
			cin >> leaveStore;

			if (leaveStore == 0)
			{
				inStore = false;
			}

		} while (inStore == true);

		bool adventuring = true;
		do {

			cout << "Try out your new weapons, comrade. (press the corresponding number to use your new weapon)" << endl;
			bool userInput = false;

			bool weaponAvailable = false;
			do {

				do {

					cin >> userSelect;
					if (userSelect <= 9 || userSelect >= 1)
					{
						userInput = true;
					}
					else {
						cout << "Sorry, I didn't catch that.  Could you try again?" << endl << endl;
					}
				} while (userInput == false);

				if (hasWeapon[userSelect] == true)
				{
					cout << "Haha my friend, try swinging a weapon you own next time." << endl;
				}
				else
				{
					weaponAvailable = true;
				}

			} while (weaponAvailable == false);

			cout <<   "sees you know your way around a weapon." << endl;
			cout << "Would you like to keep practicing? (0 for no, anything else for yes)" << endl;
			cin >> adventureMore;

			if (adventureMore == 0)
				adventuring = false;

		} while (adventuring == true);

	} while (inGame == true);
}

int main()
{
	weaponVec.push_back(new Weapon(1));
	runStore();


	system("pause");
	return 0;
}
