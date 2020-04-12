#include"Locations.h"
using namespace std;

int main() {
	World* GameWorld = new World();
	cout << "Thank you for playing!" << endl;
	delete GameWorld;
	GameWorld = nullptr;
	system("pause");
}