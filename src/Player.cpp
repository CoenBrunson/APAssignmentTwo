#include "Player.h"
#include "Utils.h"
#include "Engine.h"
#include<algorithm>

Player::Player() {
	m_isGrounded = false;
	m_dAccelX = m_dAccelY = m_dVelX = m_dVelY = 0.0;
	m_dGrav = Config::GRAV;
	m_dMaxAccelX = 4;
	m_dMaxVelX = 8;
	m_dMaxVelY = m_dGrav;
	m_dSpeed = 1.0f;
	m_dDrag = 0.75;
	m_frame = 0;
	m_frameMax = 9;
	m_frameTimer = 0;
	m_frameTimer = 15;
	m_Dir = 1;
	m_playerBounds.w = 50;
	m_playerBounds.h = 120;
	m_isAlive = true;
}

void Player::Update() {
	if (m_isAlive) {
		GetInput();
		m_dAccelX = std::min(std::max(m_dAccelX, -(m_dMaxAccelX)), (m_dMaxAccelX));
		m_dVelX = (m_dVelX + m_dAccelX) * m_dDrag;
		m_dVelX = std::min(std::max(m_dVelX, -(m_dMaxVelX)), (m_dMaxVelX));
		SetPosition(glm::vec2(GetPosition().x + (int)m_dVelX, GetPosition().y));
		m_dVelY += m_dAccelY + (m_dGrav / 5.0);
		m_dVelY = std::min(std::max(m_dVelY, -(m_dMaxVelY * 10.0)), (m_dMaxVelY));
		SetPosition(glm::vec2(GetPosition().x, GetPosition().y + (int)m_dVelY));
		m_playerBounds.x = GetPosition().x - 30;
		m_playerBounds.y = GetPosition().y - 8;
	}
}

void Player::Draw() {
	if (m_isAlive) {
		m_frameTimer++;
		if (m_frameTimer == m_frameTimerMax) {
			m_frame++;
			m_frameTimer = 0;
			if (m_frame > m_frameMax)
			{
				m_frame = 0;
			}
		}
		TextureManager::Instance()->animate("player", GetPosition().x, GetPosition().y, 64, 64, m_frameMax, m_frame, Engine::Instance().GetRenderer());
		SDL_RenderFillRect(Engine::Instance().GetRenderer(), &GetBounds());
	}
}

void Player::GetInput()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_A)) {
		m_Dir = -1;
		Move();
	}
	else if (Engine::Instance().KeyDown(SDL_SCANCODE_D)) {
		m_Dir = 1;
		Move();
	}
	if (Engine::Instance().KeyDown(SDL_SCANCODE_SPACE) && IsGrounded()) {
		m_dAccelY = 0.0 - Config::JUMPFORCE;
		SetGrounded(false);
	}
}

void Player::Move()
{
	m_dAccelX += (m_dSpeed * m_Dir);
}

void Player::Stop()
{
	m_dVelY = 0.0;
	m_dVelX = 0.0;
}

void Player::SetY(double newY)
{
	m_playerBounds.y = newY;
	SetPosition(glm::vec2(GetPosition().x, m_playerBounds.h + 8));
}

void Player::SetX(double newX)
{
	m_playerBounds.x = newX;
	SetPosition(glm::vec2(m_playerBounds.w + 30, GetPosition().y));
}
