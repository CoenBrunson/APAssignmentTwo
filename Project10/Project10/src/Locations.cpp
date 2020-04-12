#include "Locations.h"

Location::~Location()
{
	for (int i = 0; i < (int)m_vConnected.size(); i++) {
		m_vConnected[i] = nullptr;
	}
	m_vConnected.clear();
	m_vConnected.shrink_to_fit();
}

void Location::AddNeighbor(Location* neighbor)
{
	m_vConnected.push_back(neighbor);
}

void Location::displayText(int index)
{
	Story::Instance()->displayNode(index);
}

Location* Location::getNext(int index)
{
	if (index <= (int)m_vConnected.size())
		return m_vConnected[index];
	else return nullptr;
}

std::string Location::getUserInput()
{
	return std::string(); // cin for 2 strings, concat to 1, return
}

GrassLands::GrassLands(World* pWorld) : Location(pWorld)
{
	SetLocationName("Grasslands");
	SetLocationIndex(0);
	SetStartingTextIndex(0);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(1);
}

void GrassLands::sequence()
{
	Story::Instance()->read(1, 1);
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
	} while (!traveling);
	GetWorld()->GetPlayer()->SetLocationIndex(GetTravelIndex());
	GetWorld()->Travel(GetTravelIndex());
}

City::City(World* pWorld) : Location(pWorld)
{
	SetLocationName("Town");
	SetLocationIndex(1);
	SetStartingTextIndex(2);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(3);
}

void City::sequence()
{
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
	} while (!traveling);
	GetWorld()->GetPlayer()->SetLocationIndex(GetTravelIndex());
	GetWorld()->Travel(GetTravelIndex());
}

Hills::Hills(World* pWorld) : Location(pWorld)
{
	SetLocationName("Hills");
	SetLocationIndex(2);
	SetStartingTextIndex(4);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(5);
}

void Hills::sequence()
{
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
	} while (!traveling);
	GetWorld()->GetPlayer()->SetLocationIndex(GetTravelIndex());
	GetWorld()->Travel(GetTravelIndex());
}

Woods::Woods(World* pWorld) : Location(pWorld)
{
	SetLocationName("Woods");
	SetLocationIndex(3);
	SetStartingTextIndex(6);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(7);
}

void Woods::sequence()
{
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
	} while (!traveling);
	GetWorld()->GetPlayer()->SetLocationIndex(GetTravelIndex());
	GetWorld()->Travel(GetTravelIndex());
}

Temple::Temple(World* pWorld) : Location(pWorld)
{
	SetLocationName("Temple");
	SetLocationIndex(4);
	SetStartingTextIndex(8);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(9);
}

void Temple::sequence()
{
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
	} while (!traveling);
	GetWorld()->GetPlayer()->SetLocationIndex(GetTravelIndex());
	GetWorld()->Travel(GetTravelIndex());
}

Camp::Camp(World* pWorld) : Location(pWorld)
{
	SetLocationName("Camp");
	SetLocationIndex(5);
	SetStartingTextIndex(10);
	SetCurrentTextIndex(GetStartingTextIndex());
	SetEndingTextIndex(11);
}

void Camp::sequence()
{
	std::string temp;
	bool traveling = false;
	Story::Instance()->displayNode(GetStartingTextIndex()); //display location entry message
	temp = getUserInput();
	//recalculate current text index || update player state || switch player position in world
	do {
		/*
		if (GetCurrentTextIndex() && GetWorld()->GetPlayer()->GetObjective(int))
		{
			SetCurrentTextIndex(int); || m_pWorld->GetPlayer()->SetObjective(bool, int) || SetTravelIndex(int); traveling = true;
		}
		*/
		//display messages to travel can use the neighbors ("visit" 
	} while (!traveling);
	GetWorld()->Travel(GetTravelIndex());
}

World::World()
{
	m_pPlayer = new Player();
}

World::~World()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
	for (int i = 0; i < (int)m_vLocations.size(); i++) {
		delete m_vLocations[i];
		m_vLocations[i] = nullptr;
	}
	m_vLocations.clear();
	m_vLocations.shrink_to_fit();
}

void World::Start()
{
	GenerateWorld();
	ConnectWorld();
	Travel(0);
}

void World::GenerateWorld()
{
	m_vLocations.push_back(new GrassLands(this)); // 0
	m_vLocations.push_back(new City(this)); // 1
	m_vLocations.push_back(new Hills(this)); // 2
	m_vLocations.push_back(new Woods(this)); // 3
	m_vLocations.push_back(new Temple(this)); // 4
	m_vLocations.push_back(new Camp(this)); // 5
}

void World::ConnectWorld()
{
	//grasslands connected to city
	m_vLocations[0]->AddNeighbor(m_vLocations[1]);
	//city connected to grasslands, hills, woods
	m_vLocations[1]->AddNeighbor(m_vLocations[0]);
	m_vLocations[1]->AddNeighbor(m_vLocations[2]);
	m_vLocations[1]->AddNeighbor(m_vLocations[3]);
	//hills connected to city, temple
	m_vLocations[2]->AddNeighbor(m_vLocations[1]);
	m_vLocations[2]->AddNeighbor(m_vLocations[4]);
	//woods connected to city, temple
	m_vLocations[3]->AddNeighbor(m_vLocations[1]);
	m_vLocations[3]->AddNeighbor(m_vLocations[4]);
	//temple connected to hills, woods, camp
	m_vLocations[4]->AddNeighbor(m_vLocations[2]);
	m_vLocations[4]->AddNeighbor(m_vLocations[3]);
	m_vLocations[4]->AddNeighbor(m_vLocations[5]);
	//camp connected to temple, hills (secret tunnel?)
	m_vLocations[5]->AddNeighbor(m_vLocations[4]);
	m_vLocations[5]->AddNeighbor(m_vLocations[2]);
}

void World::Travel(int index)
{
	system("cls");
	GetPlayer()->SetLocationIndex(index);
	m_vLocations[GetPlayer()->GetLocationIndex()]->sequence();
}
