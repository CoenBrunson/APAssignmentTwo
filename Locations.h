#pragma once
#include<string>
#include<vector>
#include"StoryLine.h"
#include"PlayerState.h"

class World;

class Location {
private:
	World* m_pWorld;
	std::string m_locationName;
	int m_locationIndex, m_travelIndex;
	int m_startingTextIndex, m_endingTextIndex, m_currentTextIndex;
	std::vector<Location*> m_vConnected;
public:
	Location(World* pWorld) { m_pWorld = pWorld; }
	~Location();
	World* GetWorld() { return m_pWorld; }
	std::string GetLocationName() { return m_locationName; }
	void SetLocationName(std::string name) { m_locationName = name; }
	int GetLocationIndex() { return m_locationIndex; }
	void SetLocationIndex(int index) { m_locationIndex = index; }
	int GetTravelIndex() { return m_travelIndex; }
	void SetTravelIndex(int index) { m_travelIndex = index; }
	int GetStartingTextIndex() { return m_startingTextIndex; }
	void SetStartingTextIndex(int index) { m_startingTextIndex = index; }
	int GetEndingTextIndex() { return m_endingTextIndex; }
	void SetEndingTextIndex(int index) { m_endingTextIndex = index; }
	int GetCurrentTextIndex() { return m_currentTextIndex; }
	void SetCurrentTextIndex(int index) { m_currentTextIndex = index; }
	void AddNeighbor(Location* neighbor);
	void displayText(int index);
	Location* getNext(int index);
	std::string getUserInput();
	virtual void sequence() = 0; // calculates relevant text indexes based on player stats and current text index, gets user input
};

class GrassLands : public Location {
public:
	GrassLands(World* pWorld);
	~GrassLands() {}
	void sequence();
};

class City : public Location {
public:
	City(World* pWorld);
	~City() {}
	void sequence();
};

class Hills : public Location {
public:
	Hills(World* pWorld);
	~Hills() {}
	void sequence();
};

class Woods : public Location {
public:
	Woods(World* pWorld);
	~Woods() {}
	void sequence();
};

class Temple : public Location {
public:
	Temple(World* pWorld);
	~Temple() {}
	void sequence();
};

class Camp : public Location {
public:
	Camp(World* pWorld);
	~Camp() {}
	void sequence();
};

class World {
private:
	Player* m_pPlayer;
	std::vector<Location*> m_vLocations;
public:
	World();
	~World();
	Player* GetPlayer() { return m_pPlayer; }
	void GenerateWorld();
	void ConnectWorld();
	void Travel(int index);
};