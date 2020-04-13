#include "SetDressing.h"

BackGround::BackGround() {
	glm::vec2 size = TextureManager::Instance()->getTextureSize("background");
	SetWidth(size.x);
	SetHeight(size.y);
	SetPosition(vec2(GetWidth() / 2, GetHeight() / 2));
}

void BackGround::Draw() {
	TextureManager::Instance()->draw("background", GetPosition().x, GetPosition().y, Engine::Instance().GetRenderer(), true);
}