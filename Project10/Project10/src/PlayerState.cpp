#include "PlayerState.h"

Player::Player() {
	SetLocationIndex(0);
	SetNumObjectives(10); // **Needs to change depending on how many objectives player will have**
	for (int i = 0; i < GetNumObjectives(); i++) {
		m_objectives.push_back(new bool);
		SetObjective(false, i);
	}
}
