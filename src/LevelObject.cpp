#include "LevelObject.h"
#include "TextureManager.h"
#include "Engine.h"
#include <math.h>

void BackGround::Draw()
{
	TextureManager::Instance()->draw("background", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
}

void MidGround::Draw()
{
	TextureManager::Instance()->draw("midground", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
}

void Platform::Update()
{
	SDL_Rect temp;
	temp.x = GetPosition().x - Config::TILE_SIZE / 2;
	temp.y = GetPosition().y - Config::TILE_SIZE / 2;
	temp.w = GetBounds().w;
	temp.h = GetBounds().h;
	SetBounds(temp);
}

void Platform::Draw()
{
	TextureManager::Instance()->draw("platform", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &GetBounds());
}

void ForeGround::Draw()
{
	TextureManager::Instance()->draw("foreground", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
}

Pepper::Pepper()
{
	SetObjectType(HAZARD);
	xValue = 0;
	yValue = 0;
}

void Pepper::Update()
{
	xValue += 1;
	yValue = 15 * sin(xValue/20);
	SetPosition(glm::vec2(GetPosition().x, GetPosition().y + yValue));
	SDL_Rect temp;
	temp.x = GetPosition().x - Config::TILE_SIZE / 2;
	temp.y = GetPosition().y - Config::TILE_SIZE / 2;
	temp.w = GetBounds().w;
	temp.h = GetBounds().h;
	SetBounds(temp);
}

void Pepper::Draw()
{
	TextureManager::Instance()->draw("pepper", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &GetBounds());
}

void Bullet::Update()
{
	SetPosition(glm::vec2(GetPosition().x - 10, GetPosition().y));
	SDL_Rect temp;
	temp.x = GetPosition().x - Config::TILE_SIZE / 2;
	temp.y = GetPosition().y - Config::TILE_SIZE / 2;
	temp.w = GetBounds().w;
	temp.h = GetBounds().h;
	SetBounds(temp);
}

void Bullet::Draw()
{
	TextureManager::Instance()->draw("bullet", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &GetBounds());
}

void Box::Update()
{
	SetPosition(glm::vec2(GetPosition().x, GetPosition().y + 9));
	SDL_Rect temp;
	temp.x = GetPosition().x - Config::TILE_SIZE / 2;
	temp.y = GetPosition().y - Config::TILE_SIZE / 2;
	temp.w = GetBounds().w;
	temp.h = GetBounds().h;
	SetBounds(temp);
}

void Box::Draw()
{
	TextureManager::Instance()->draw("box", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &GetBounds());
}
