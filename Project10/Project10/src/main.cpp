#include"Locations.h"
using namespace std;

int main() {
	World* GameWorld = new World();
	GameWorld->Start();
	cout << "Thank you for playing!" << endl;
	delete GameWorld;
	GameWorld = nullptr;
	Story::Instance()->scriptFile.close();
	system("pause");
}