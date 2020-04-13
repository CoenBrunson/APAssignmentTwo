#pragma once
#include "Actor.h"
#include "SimpleStates.h"

class Button : public Actor {
private:
	ButtonType m_buttonType;
	ButtonState m_currentState;
	SDL_Rect bounds;
public:
	Button(ButtonType type, vec2 position);
	void SetButtonType(ButtonType type) { m_buttonType = type; }
	ButtonType GetButtonType() { return m_buttonType; }
	void SetButtonState(ButtonState state) { m_currentState = state; }
	ButtonState GetButtonState() { return m_currentState; }
	void Update();
	void Draw();
	void Clean() {}
};

class Menu : public Actor {
private:
	int m_buttonCount;
protected:
	std::vector<Button*> m_vButtons;
public:
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
	int GetButtonCount() { return m_buttonCount; }
	void SetButtonCount(int count) { m_buttonCount = count; }
};

class StartMenu : protected Menu {
private:
	//Mix_Music* m_music;
public:
	StartMenu();
	~StartMenu() {}
	void Update();
	void Draw();
	void Clean() {}
};

class PauseMenu : protected Menu {
private:
public:
	PauseMenu();
	~PauseMenu() {}
	void Update();
	void Draw();
	void Clean() {}
};

class GameOverMenu : protected Menu {
private:
	//Mix_Music* m_music;
public:
	GameOverMenu();
	~GameOverMenu() {}
	void Update();
	void Draw();
	void Clean() {}
};