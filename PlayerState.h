#pragma once
#include<vector>
#include<string>

class Player {
private:
	int m_locationIndex, m_numObjectives;
	//objectives
	std::vector<bool> m_objectives;
public:
	Player();
	~Player() {}
	int GetLocationIndex() { return m_locationIndex; }
	void SetLocationIndex(int index) { m_locationIndex = index; }
	int GetNumObjectives() { return m_numObjectives; }
	void SetNumObjectives(int num) { m_numObjectives = num; }
	bool GetObjective(int index) { return m_objectives[index]; }
	void SetObjective(bool completed, int index) { m_objectives[index] = completed; }
};