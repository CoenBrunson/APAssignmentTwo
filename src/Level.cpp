#include "Level.h"
#include "Engine.h"
#include "Utils.h"
#include <algorithm>

Level::Level()
{
	m_vBackGround.push_back(new BackGround());
	m_vBackGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT / 2));
	m_vBackGround.push_back(new BackGround());
	m_vBackGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3, Config::SCREEN_HEIGHT / 2));
	m_vMidGround.push_back(new MidGround());
	m_vMidGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT / 2));
	m_vMidGround.push_back(new MidGround());
	m_vMidGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3, Config::SCREEN_HEIGHT / 2));
	m_vForeGround.push_back(new ForeGround());
	m_vForeGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT / 2));
	m_vForeGround.push_back(new ForeGround());
	m_vForeGround.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3, Config::SCREEN_HEIGHT / 2));
	for (int i = 0; i < 20; i++) {
		m_vPlatforms.push_back(new Platform);
		m_vPlatforms.back()->SetPosition(glm::vec2(Config::TILE_SIZE*(i+1), 650));
	}
	m_pPlayer = new Player();
	m_pPlayer->SetPosition(glm::vec2(120, 400));
	m_pPlayer->SetGrounded(false);
}

Level::~Level()
{
	for (int i = 0; i < 2; i++) {
		delete m_vBackGround[i];
		delete m_vMidGround[i];
		delete m_vForeGround[i];
	}
	m_vBackGround.clear();
	m_vBackGround.shrink_to_fit();
	m_vMidGround.clear();
	m_vMidGround.shrink_to_fit();
	m_vForeGround.clear();
	m_vForeGround.shrink_to_fit();
	for (int i = 0; i < (int)m_vPlatforms.size(); i++) {
		delete m_vPlatforms[i];
		m_vPlatforms[i] = nullptr;
	}
	m_vPlatforms.clear();
	m_vPlatforms.shrink_to_fit();
	for (int i = 0; i < (int)m_vPeppers.size(); i++) {
		delete m_vPeppers[i];
		m_vPeppers[i] = nullptr;
	}
	m_vPeppers.clear();
	m_vPeppers.shrink_to_fit();
	for (int i = 0; i < (int)m_vBullets.size(); i++) {
		delete m_vBullets[i];
		m_vBullets[i] = nullptr;
	}
	m_vBullets.clear();
	m_vBullets.shrink_to_fit();
	for (int i = 0; i < (int)m_vBoxes.size(); i++) {
		delete m_vBoxes[i];
		m_vBoxes[i] = nullptr;
	}
	m_vBoxes.clear();
	m_vBoxes.shrink_to_fit();
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void Level::Update()
{
	if ((int)m_vPlatforms.size() != 0) {
		for (int i = 0; i < (int)m_vPlatforms.size(); i++) {
			m_vPlatforms[i]->Update();
		}
	}
	if ((int)m_vPeppers.size() != 0) {
		for (int i = 0; i < (int)m_vPeppers.size(); i++) {
			m_vPeppers[i]->Update();
		}
	}
	if ((int)m_vBullets.size() != 0) {
		for (int i = 0; i < (int)m_vBullets.size(); i++) {
			m_vBullets[i]->Update();
		}
	}
	if ((int)m_vBoxes.size() != 0) {
		for (int i = 0; i < (int)m_vBoxes.size(); i++) {
			m_vBoxes[i]->Update();
		}
	}
	SpawnHazard();
	//Scroll();
	m_pPlayer->Update();
	CheckCollision();
	CleanGarbage();
}

void Level::Draw()
{
	m_vBackGround[0]->Draw();
	m_vBackGround[1]->Draw();
	m_vMidGround[0]->Draw();
	m_vMidGround[1]->Draw();
	if (!m_vPlatforms.empty()) {
		for (int i = 0; i < (int)m_vPlatforms.size(); i++) {
			m_vPlatforms[i]->Draw();
		}
	}
	if ((int)m_vPeppers.size() != 0) {
		for (int i = 0; i < (int)m_vPeppers.size(); i++) {
			m_vPeppers[i]->Draw();
		}
	}
	if ((int)m_vBullets.size() != 0) {
		for (int i = 0; i < (int)m_vBullets.size(); i++) {
			m_vBullets[i]->Draw();
		}
	}
	if ((int)m_vBoxes.size() != 0) {
		for (int i = 0; i < (int)m_vBoxes.size(); i++) {
			m_vBoxes[i]->Draw();
		}
	}
	m_pPlayer->Draw();
	m_vForeGround[0]->Draw();
	m_vForeGround[1]->Draw();
	if (!m_pPlayer->GetAlive()) {
		Engine::Instance().GetFSM().ChangeState(new GameOverState);
	}
}

void Level::Scroll()
{
	for (int i = 0; i < 2; i++) {
		m_vBackGround[i]->SetPosition(glm::vec2(m_vBackGround[i]->GetPosition().x - Config::BG_SCROLL_SPEED, m_vBackGround[i]->GetPosition().y));
		if (m_vBackGround[i]->GetPosition().x < 0 - Config::SCREEN_WIDTH) {
			m_vBackGround[i]->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3 - 20, Config::SCREEN_HEIGHT / 2));
		}
		m_vMidGround[i]->SetPosition(glm::vec2(m_vMidGround[i]->GetPosition().x - Config::PLAYER_MOVE_SPEED, m_vMidGround[i]->GetPosition().y));
		if (m_vMidGround[i]->GetPosition().x < 0 - Config::SCREEN_WIDTH) {
			m_vMidGround[i]->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3 - 20, Config::SCREEN_HEIGHT / 2));
		}
		m_vForeGround[i]->SetPosition(glm::vec2(m_vForeGround[i]->GetPosition().x - Config::FG_SCROLL_SPEED, m_vForeGround[i]->GetPosition().y));
		if (m_vForeGround[i]->GetPosition().x < 0 - Config::SCREEN_WIDTH) {
			m_vForeGround[i]->SetPosition(glm::vec2(Config::SCREEN_WIDTH * 3 - 40, Config::SCREEN_HEIGHT / 2));
		}
	}
	if ((int)m_vPlatforms.size() != 0) {
		for (int i = 0; i < (int)m_vPlatforms.size(); i++) {
			m_vPlatforms[i]->SetPosition(glm::vec2(m_vPlatforms[i]->GetPosition().x - Config::PLAYER_MOVE_SPEED, m_vPlatforms[i]->GetPosition().y));
		}
	}
	if ((int)m_vPeppers.size() != 0) {
		for (int i = 0; i < (int)m_vPeppers.size(); i++) {
			m_vPeppers[i]->SetPosition(glm::vec2(m_vPeppers[i]->GetPosition().x - Config::PLAYER_MOVE_SPEED, m_vPeppers[i]->GetPosition().y));
		}
	}
	if ((int)m_vBullets.size() != 0) {
		for (int i = 0; i < (int)m_vBullets.size(); i++) {
			m_vBullets[i]->SetPosition(glm::vec2(m_vBullets[i]->GetPosition().x - Config::PLAYER_MOVE_SPEED, m_vBullets[i]->GetPosition().y));
		}
	}
	if ((int)m_vBoxes.size() != 0) {
		for (int i = 0; i < (int)m_vBoxes.size(); i++) {
			m_vBoxes[i]->SetPosition(glm::vec2(m_vBoxes[i]->GetPosition().x - Config::PLAYER_MOVE_SPEED, m_vBoxes[i]->GetPosition().y));
		}
	}
}

void Level::SpawnFloor()
{
	int platformChance = rand() % 100;
	if (platformChance > 1) {
		m_vPlatforms.push_back(new Platform);
		m_vPlatforms.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH + Config::TILE_SIZE / 2, 650));
	}
}

void Level::SpawnHazard()
{
	int hazardChance = rand() % 100;
	if (hazardChance < 1) {
		int hazard = rand() % 3;
		switch (hazard) {
		case 0:
			m_vBullets.push_back(new Bullet);
			m_vBullets.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH, 570));
			break;
		case 1:
			m_vPeppers.push_back(new Pepper);
			m_vPeppers.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH, 200 + rand()%300));
			break;
		case 2:
			m_vBoxes.push_back(new Box);
			m_vBoxes.back()->SetPosition(glm::vec2(Config::SCREEN_WIDTH - rand() % 600, 0));
			break;
		}
	}
}

void Level::CheckCollision()
{
	if ((int)m_vPlatforms.size() != 0) {
		for (int i = 0; i < (int)m_vPlatforms.size()-1; i++) {
			if ((m_pPlayer->GetBounds().y + m_pPlayer->GetBounds().h) - m_pPlayer->GetVelY() <= m_vPlatforms[i]->GetBounds().y)
			{
				m_pPlayer->SetGrounded(true);
				m_pPlayer->SetVelY(0.0);
				m_pPlayer->SetY(m_vPlatforms[i]->GetBounds().y - m_pPlayer->GetBounds().h-1);
			}
			else if (((int)m_pPlayer->GetBounds().x + m_pPlayer->GetBounds().w) - m_pPlayer->GetVelX() <= m_vPlatforms[i]->GetBounds().x)
			{
				m_pPlayer->SetVelX(0.0);
				m_pPlayer->SetX(m_vPlatforms[i]->GetBounds().x - m_pPlayer->GetBounds().w);
			}
			else if (m_pPlayer->GetBounds().x - m_pPlayer->GetVelX() >= m_vPlatforms[i]->GetBounds().x + m_vPlatforms[i]->GetBounds().w)
			{
				m_pPlayer->SetVelX(0.0);
				m_pPlayer->SetX(m_vPlatforms[i]->GetBounds().x + m_vPlatforms[i]->GetBounds().w);
			}
		}
	}
	if ((int)m_vPeppers.size() != 0) {
		for (int i = 0; i < (int)m_vPeppers.size(); i++) {
			if (Utils::AABB(m_pPlayer, m_vPeppers[i]))
			{
				m_pPlayer->Kill();
			}
		}
	}
	if ((int)m_vBullets.size() != 0) {
		for (int i = 0; i < (int)m_vBullets.size(); i++) {
			if (Utils::AABB(m_pPlayer, m_vPeppers[i]))
			{
				m_pPlayer->Kill();
			}
		}
	}
	if ((int)m_vBoxes.size() != 0) {
		for (int i = 0; i < (int)m_vBoxes.size(); i++) {
			if (Utils::AABB(m_pPlayer, m_vPeppers[i]))
			{
				m_pPlayer->Kill();
			}
		}
	}
	if (m_pPlayer->GetPosition().y > Config::SCREEN_HEIGHT)
		m_pPlayer->Kill();
}

void Level::CleanGarbage()
{
	if ((int)m_vPlatforms.size() != 0) {
		for (int i = 0; i < (int)m_vPlatforms.size(); i++) {
			if (m_vPlatforms[i]->GetPosition().x < 0 - Config::TILE_SIZE) {
				delete m_vPlatforms[i];
				m_vPlatforms[i] = nullptr;
				SpawnFloor();
			}
		}
		m_vPlatforms.erase(remove(m_vPlatforms.begin(), m_vPlatforms.end(), nullptr), m_vPlatforms.end());
		m_vPlatforms.shrink_to_fit();
	}
	if ((int)m_vPeppers.size() != 0) {
		for (int i = 0; i < (int)m_vPeppers.size(); i++) {
			if (m_vPeppers[i]->GetPosition().x < 0 - Config::TILE_SIZE) {
				delete m_vPeppers[i];
				m_vPeppers[i] = nullptr;
			}
		}
		m_vPeppers.erase(remove(m_vPeppers.begin(), m_vPeppers.end(), nullptr), m_vPeppers.end());
		m_vPeppers.shrink_to_fit();
	}
	if ((int)m_vBoxes.size() != 0) {
		for (int i = 0; i < (int)m_vBoxes.size(); i++) {
			if (m_vBoxes[i]->GetPosition().x < 0 - Config::TILE_SIZE) {
				delete m_vBoxes[i];
				m_vBoxes[i] = nullptr;
			}
		}
		m_vBoxes.erase(remove(m_vBoxes.begin(), m_vBoxes.end(), nullptr), m_vBoxes.end());
		m_vBoxes.shrink_to_fit();
	}
	if ((int)m_vBullets.size() != 0) {
		for (int i = 0; i < (int)m_vBullets.size(); i++) {
			if (m_vBullets[i]->GetPosition().x < 0 - Config::TILE_SIZE) {
				delete m_vBullets[i];
				m_vBullets[i] = nullptr;
			}
		}
		m_vBullets.erase(remove(m_vBullets.begin(), m_vBullets.end(), nullptr), m_vBullets.end());
		m_vBullets.shrink_to_fit();
	}
}
