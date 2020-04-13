#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <glm/vec2.hpp>
#include "ObjectType.h"

using namespace glm;

class Actor {
private:
	vec2 m_position;
	int m_height, m_width;
	SDL_Rect m_bounds;
	ObjectType m_type;

protected:
	std::string m_textureID;

public:
	Actor();
	~Actor() {}
	vec2 GetPosition() { return m_position; }
	void SetPosition(vec2 newPosition) { m_position = newPosition; }
	int GetHeight() { return m_height; }
	void SetHeight(int newHeight) { m_height = newHeight; }
	int GetWidth() { return m_width; }
	void SetWidth(int newWidth) { m_width = newWidth; }
	ObjectType GetObjectType() { return m_type; }
	SDL_Rect GetBounds() { return m_bounds; }
	void SetBounds(SDL_Rect bounds) { m_bounds = bounds; }
	void SetObjectType(ObjectType type) { m_type = type; }

	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Clean() = 0;
};