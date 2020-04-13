#include "Actor.h"
#include "Engine.h"
#include "Utils.h"
#include "Config.h"

Actor::Actor(){
	m_position = vec2(0, 0);
	SetBounds(SDL_Rect{0, 0, Config::TILE_SIZE, Config::TILE_SIZE});
}
