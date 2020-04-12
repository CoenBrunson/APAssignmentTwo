#include"Locations.h"
using namespace std;

int main() {
	Story::Instance()->scriptFile.open("scriptFile.txt");
	if (Story::Instance()->scriptFile.is_open())
		cout << "Script successful." << endl;
	else
		std::cout << "Error opening script." << std::endl;
	World* GameWorld = new World();
	cout << "Thank you for playing!" << endl;
	delete GameWorld;
	GameWorld = nullptr;
	Story::Instance()->scriptFile.close();
	system("pause");
}