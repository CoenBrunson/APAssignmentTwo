#include "StoryLine.h"
Story* Story::s_pInstance;

Story::Story() {
	head = nullptr;
	tail = nullptr;
	scriptFile.open("scriptFile.txt");
	if (scriptFile.is_open()) {
		std::cout << "Script successful." << std::endl;
	}
	else
		std::cout << "Error opening script." << std::endl;
}

Story::~Story() // deletes all nodes in the story list
{
	StoryNode* current = head;
	StoryNode* next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
	scriptFile.close();
}

void Story::read(int x, int y)//**********************TODO*********************************
{
	//index = 0. open istream, for each line in text, save line to string, push string and index into add fuction. close istream
	if (scriptFile.is_open())
	{
		GotoLine(scriptFile, x);
		for (int i = 0; i < y; i++)
		{
			std::string temp;
			getline(scriptFile, speechString);
			std::cout << "added line" << std::endl;

		}
	}
}

void Story::add(std::string in, int indx) // adds a node to the end of the list
{
	StoryNode* temp = new StoryNode();
	temp->index = indx;
	temp->text = in;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
}

void Story::displayNode(int index) //displays the text of a node with the required index
{
	StoryNode* temp;
	temp = head;
	while (temp != NULL) {
		if (temp->index == index) {
			std::cout << temp->text << std::endl;
		}
		temp = temp->next;
	}
}

std::fstream& Story::GotoLine(std::fstream& file, unsigned int num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num; ++i) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}
