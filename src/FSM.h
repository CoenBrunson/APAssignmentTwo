#pragma once
#include<vector>
#include "Level.h"
#include "Menu.h"
#include "SimpleStates.h"
#include "TextureManager.h"
#include "SoundManager.h"

class State {
protected:
	State() {}
	FSMState m_currentState;
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
	virtual void Resume() {}
	virtual void Exit() = 0;
	FSMState GetCurrentState() { return m_currentState; }
	void SetCurrentState(FSMState state) { m_currentState = state; }
};

class TitleState : public State {
private:
	StartMenu* m_menu;
public:
	TitleState() {}
	void Enter();
	void Update();
	void Render();
	void Exit();
};

class PauseState : public State {
private:
	PauseMenu* m_menu;
public:
	PauseState() {}
	void Enter();
	void Update();
	void Render();
	void Exit();
};

class GameOverState : public State {
private:
	GameOverMenu* m_menu;
public:
	GameOverState() {}
	void Enter();
	void Update();
	void Render();
	void Exit();
};

class GameState : public State
{
private:
	Level* m_level;
public:
	GameState() {}
	void Enter();
	void Update();
	void Render();
	void Exit();
	void Resume() { std::cout << "Resuming Game..." << std::endl; }
};

class FSM {
private:
	std::vector<State*> m_vStates;
public:
	FSM() {}
	~FSM() {}
	void Update();
	void Render();
	void ChangeState(State* pState);
	void PushState(State* pState);
	void PopState();
	void Clean();
	static void loadAssets();
	std::vector<State*>& GetStates() { return m_vStates; }
};