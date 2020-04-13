#pragma once
#include <math.h>
#include "Actor.h"

class Utils {
private:
	Utils();
	~Utils() {}
public:
	static bool AABB(Actor* obj1, Actor* obj2);
	static bool PointAABB(SDL_Point point, SDL_Rect* object);
	static float Magnitude(vec2 vector);
	static vec2 Normalize(vec2 vector);
	static vec2 Limit(vec2 vector, float magnitude);
};