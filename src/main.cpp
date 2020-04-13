//Andrey Chizhov 101255069 February 23, 2020
//This program is a shooter game featuring a fully flushed out FSM driving the menu system, and new and improved graphics
//Controls: WASD to move, Spacebar to shoot, and Escape to enter Pause Menu
#include "Engine.h"

int main(int argc, char* args[]){
	return Engine::Instance().Run();
}