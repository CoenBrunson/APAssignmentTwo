#pragma once
enum PlayerState {
	STANDING,
	RUNNING_FORWARD,
	RUNNING_BACKWARD,
	JUMPING,
	FALLING,
	DEAD
};

enum ButtonState {
	IDLE,
	SELECTED
};

enum FSMState {
	TITLE,
	PAUSE,
	GAME,
	GAME_OVER
};