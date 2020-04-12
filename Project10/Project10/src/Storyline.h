#pragma once
#include<string>
#include<fstream>
#include<iostream>

struct StoryNode {
	int index;
	std::string text;
	StoryNode* next;
};

class Story {
private:
	static Story* s_pInstance;
	StoryNode *head, *tail;
	std::string input;
	std::string speechString;
public:
	std::fstream scriptFile;
	static Story* Instance() {
		if (s_pInstance == nullptr) {
			s_pInstance = new Story();
			return s_pInstance;
		}
		return s_pInstance;
	}
	Story();
	~Story();
	void read(int x, int y); // function for fstream, save line of file to string and call add() function
	void add(std::string in, int indx);
	void displayNode(int index);
	std::fstream& GotoLine(std::fstream& file, unsigned int num);
};