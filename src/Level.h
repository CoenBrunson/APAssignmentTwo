#pragma once
#include "Player.h"
#include "LevelObject.h"

class Level {
private:
	std::vector<BackGround*> m_vBackGround;
	std::vector<MidGround*> m_vMidGround;
	std::vector<ForeGround*> m_vForeGround;
	std::vector<Platform*> m_vPlatforms;
	std::vector<Pepper*> m_vPeppers;
	std::vector<Bullet*> m_vBullets;
	std::vector<Box*> m_vBoxes;
	Player* m_pPlayer;
public:
	Level();
	~Level();
	void Update();
	void Draw();
	void Scroll();
	void SpawnFloor();
	void SpawnHazard();
	void CheckCollision();
	void CleanGarbage();
};