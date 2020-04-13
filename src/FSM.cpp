#include <algorithm>
#include "Utils.h"
#include "Engine.h"
#include "TextureManager.h"
#include "SimpleStates.h"
#include <time.h>

void FSM::Update()
{
	if (!m_vStates.empty())
		m_vStates.back()->Update();
}

void FSM::Render()
{
	if (!m_vStates.empty())
		m_vStates.back()->Render();
}

void FSM::ChangeState(State* pState)
{
	if (!m_vStates.empty())
	{
		m_vStates.back()->Exit();
		delete m_vStates.back();	
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
	PushState(pState);
}

void FSM::PushState(State* pState)
{
	m_vStates.push_back(pState);
	m_vStates.back()->Enter();
}

void FSM::PopState()
{
	if (!m_vStates.empty())
	{
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
	m_vStates.back()->Resume();
}

void FSM::Clean()
{
	while (!m_vStates.empty())
	{
		m_vStates.back()->Exit();
		delete m_vStates.back();
		m_vStates.back() = nullptr;
		m_vStates.pop_back();
	}
}

void FSM::loadAssets()
{
	TextureManager::Instance()->load("../Assets/Player.png", "player", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Background.png", "background", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Continue_Button.png", "continue_button", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Death_Screen.png", "death_menu", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Foreground.png", "foreground", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Midground.png", "midground", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Pause_Screen.png", "pause_menu", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Platform.png", "platform", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Quit_Button.png", "quit_button", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Restart_Button.png", "restart_button", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Start_Button.png", "start_button", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Title_Screen.png", "start_menu", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Bullet.png", "bullet", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Pepper.png", "pepper", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Death_Box.png", "box", Engine::Instance().GetRenderer());
	TextureManager::Instance()->load("../Assets/Explosion.png", "explosion", Engine::Instance().GetRenderer());
	srand(time(NULL));
}

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}

void TitleState::Enter()
{
	SetCurrentState(TITLE);
	FSM::loadAssets();
	m_menu = new StartMenu();
}

void TitleState::Update()
{
	m_menu->Update();
}

void TitleState::Render()
{
	std::cout << "Rendering Title..." << std::endl;
	SDL_RenderClear(Engine::Instance().GetRenderer());
	m_menu->Draw();
	State::Render();
}

void TitleState::Exit()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	std::cout << "Exiting Title..." << std::endl;
	delete m_menu;
	m_menu = nullptr;
}

void PauseState::Enter()
{
	SetCurrentState(PAUSE);
	m_menu = new PauseMenu;
}

void PauseState::Update()
{
	m_menu->Update();
}

void PauseState::Render()
{
	Engine::Instance().GetFSM().GetStates().front()->Render();
	m_menu->Draw();
	State::Render();
}

void PauseState::Exit()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	delete m_menu;
	m_menu = nullptr;
}

void GameState::Enter()
{
	SetCurrentState(GAME);
	m_level = new Level;
}

void GameState::Update()
{
	m_level->Update();
}

void GameState::Render()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	m_level->Draw();
	if (dynamic_cast<GameState*>(Engine::Instance().GetFSM().GetStates().back()))
		State::Render();
}

void GameState::Exit()
{
	delete m_level;
	m_level = nullptr;
}

void GameOverState::Enter()
{
	SetCurrentState(GAME_OVER);
	m_menu = new GameOverMenu;
}

void GameOverState::Update()
{
	m_menu->Update();
}

void GameOverState::Render()
{
	std::cout << "Rendering Game Over..." << std::endl;
	SDL_RenderClear(Engine::Instance().GetRenderer());
	m_menu->Draw();
	State::Render();
}

void GameOverState::Exit()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	std::cout << "Exiting Game Over..." << std::endl;
	delete m_menu;
	m_menu = nullptr;
}
