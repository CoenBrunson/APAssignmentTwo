#pragma once
#include "Actor.h"

class Player : public Actor {
private:
	SDL_Rect m_playerBounds;
	vec2 newPosition;
	bool m_isGrounded, m_isAlive;
	int m_frame, m_frameMax, m_frameTimer, m_frameTimerMax, m_Dir;
	double m_dAccelX,
		m_dMaxAccelX,
		m_dAccelY,
		m_dVelX,
		m_dMaxVelX,
		m_dVelY,
		m_dMaxVelY,
		m_dSpeed,
		m_dDrag,
		m_dGrav;
public:
	Player();
	~Player() {}
	bool IsGrounded() { return m_isGrounded; }
	void SetGrounded(bool collision) { m_isGrounded = collision; }
	SDL_Rect GetBounds() { return m_playerBounds; }

	void Update();
	void Draw();
	void Clean() {}
	void GetInput();
	void Move();
	void Stop();
	void SetAccelerationY(double accel) { m_dAccelY = accel; }
	double GetVelY() { return m_dVelY; }
	void SetVelY(double velY) { m_dVelY = velY; }
	double GetVelX() { return m_dVelX; }
	void SetVelX(double velX) { m_dVelX = velX; }
	void SetY(double newY);
	void SetX(double newX);
	void Kill() { m_isAlive = false; }
	bool GetAlive() { return m_isAlive; }
};