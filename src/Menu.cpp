#include "Menu.h"
#include "Engine.h"
#include "SimpleStates.h"
#include "Utils.h"

StartMenu::StartMenu()
{
	glm::vec2 size = TextureManager::Instance()->getTextureSize("start_menu");
	SetWidth(size.x);
	SetHeight(size.y);
	SetPosition(vec2(GetWidth() / 2, GetHeight() / 2));
	SetObjectType(ObjectType::START_MENU);
	m_vButtons.push_back(new Button(ButtonType::START, vec2(830, 200)));
	m_vButtons.push_back(new Button(ButtonType::QUIT, vec2(830, 400)));
}

void StartMenu::Draw()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	TextureManager::Instance()->draw("start_menu", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Draw();
	}
}

PauseMenu::PauseMenu()
{
	glm::vec2 size = TextureManager::Instance()->getTextureSize("pause_menu");
	SetWidth(size.x);
	SetHeight(size.y);
	SetPosition(vec2(Config::SCREEN_WIDTH/2, Config::SCREEN_HEIGHT/2));
	SetObjectType(ObjectType::PAUSE_MENU);
	m_vButtons.push_back(new Button(ButtonType::RESUME, vec2(730, 200)));
	m_vButtons.push_back(new Button(ButtonType::QUIT, vec2(730, 400)));
}

void PauseMenu::Draw()
{
	TextureManager::Instance()->draw("pause_menu", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Draw();
	}
}

GameOverMenu::GameOverMenu()
{
	glm::vec2 size = TextureManager::Instance()->getTextureSize("game_over_menu");
	SetWidth(size.x);
	SetHeight(size.y);
	SetPosition(vec2(GetWidth() / 2, GetHeight() / 2));
	SetObjectType(ObjectType::OVER_MENU);
	m_vButtons.push_back(new Button(ButtonType::RESTART, vec2(830, 200)));
	m_vButtons.push_back(new Button(ButtonType::QUIT, vec2(830, 400)));
}

void GameOverMenu::Draw()
{
	SDL_RenderClear(Engine::Instance().GetRenderer());
	TextureManager::Instance()->draw("game_over_menu", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Draw();
	}
}

Button::Button(ButtonType type, vec2 position)
{
	SetWidth(300);
	SetHeight(80);
	SetPosition(position);
	SetButtonType(type);
	bounds.w = GetWidth();
	bounds.h = GetHeight();
	bounds.x = GetPosition().x;
	bounds.y = GetPosition().y;
}

void Button::Update()
{
	SetButtonState(IDLE);
	if (Utils::PointAABB(Engine::Instance().GetMousePosition(), &bounds)) {
		SetButtonState(SELECTED);
		if (Engine::Instance().GetMouseDown()) {
			switch (GetButtonType()) {
			case START:
				Engine::Instance().GetFSM().ChangeState(new GameState);
				break;
			case RESUME:
				Engine::Instance().GetFSM().PopState();
				break;
			case RESTART:
				Engine::Instance().GetFSM().ChangeState(new GameState);
				break;
			case QUIT:
				if (Engine::Instance().GetFSM().GetStates().back()->GetCurrentState() == FSMState::TITLE)
					 Engine::Instance().Quit();
				else Engine::Instance().GetFSM().ChangeState(new TitleState);
				break;
			default:
				break;
			}
		}
	}
}

void Button::Draw()
{
	switch (GetButtonType()) {
	case START:
		if (GetButtonState() == IDLE) TextureManager::Instance()->drawButton("start_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), false, Engine::Instance().GetRenderer());
		else if (GetButtonState() == SELECTED) TextureManager::Instance()->drawButton("start_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), true, Engine::Instance().GetRenderer());
		break;
	case RESUME:
		if (GetButtonState() == IDLE) TextureManager::Instance()->drawButton("continue_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), false, Engine::Instance().GetRenderer());
		else if (GetButtonState() == SELECTED) TextureManager::Instance()->drawButton("continue_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), true, Engine::Instance().GetRenderer());
		break;
	case RESTART:
		if (GetButtonState() == IDLE) TextureManager::Instance()->drawButton("restart_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), false, Engine::Instance().GetRenderer());
		else if (GetButtonState() == SELECTED) TextureManager::Instance()->drawButton("restart_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), true, Engine::Instance().GetRenderer());
		break;
	case QUIT:
		if (GetButtonState() == IDLE) TextureManager::Instance()->drawButton("quit_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), false, Engine::Instance().GetRenderer());
		else if (GetButtonState() == SELECTED) TextureManager::Instance()->drawButton("quit_button", GetPosition().x, GetPosition().y, GetWidth(), GetHeight(), true, Engine::Instance().GetRenderer());
		break;
	default:
		break;
	}
}

void StartMenu::Update()
{
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Update();
	}
}

void PauseMenu::Update()
{
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Update();
	}
}

void GameOverMenu::Update()
{
	for (int i = 0; i < (int)m_vButtons.size(); i++) {
		m_vButtons[i]->Update();
	}
}
