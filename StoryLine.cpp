#include "StoryLine.h"

Story* Story::s_pInstance;

Story::Story() {
		head = nullptr;
		tail = nullptr;
		read();
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
}

void Story::read()//**********************TODO*********************************
{
	//index = 0. open istream, for each line in text, save line to string, push string and index into add fuction. close istream
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
		if (temp->index == index)
			std::cout << temp->text << std::endl;
		temp = temp->next;
	}
}
