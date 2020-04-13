#include <iostream>
#include "Utils.h"

bool Utils::AABB(Actor* obj1, Actor* obj2){
	glm::vec2 P1 = obj1->GetPosition();
	glm::vec2 P2 = obj2->GetPosition();
	float P1width = obj1->GetBounds().w;
	float P1height = obj1->GetBounds().h;
	float P2width = obj2->GetBounds().w;
	float P2height = obj2->GetBounds().h;

	if (
		P1.x < P2.x + P2width &&
		P1.x + P1width > P2.x&&
		P1.y < P2.y + P2height &&
		P1.y + P1height > P2.y
		){
		return true;
	}
	return false;
}

bool Utils::PointAABB(SDL_Point point, SDL_Rect* object){
	if (point.x < (object->x + object->w) && point.x > object->x &&
		point.y < (object->y + object->h) && point.y > object->y) {
		return true;
	}
	return false;
}

float Utils::Magnitude(glm::vec2 vec){
	float x = vec.x;
	float y = vec.y;
	return sqrt((x * x) + (y * y));
}

vec2 Utils::Normalize(vec2 vector){
	vec2 dest;
	float x = vector.x;
	float y = vector.y;
	float length = (x * x) + (y * y);
	if (length > 0) {
		length = 1.0 / sqrt(length);
		dest.x = vector.x * length;
		dest.y = vector.y * length;
	}
	return dest;
}

vec2 Utils::Limit(vec2 vector, float magnitude){
	float length = Utils::Magnitude(vector);

	if (length > magnitude) {
		float limiter = magnitude / length;
		vector.x *= limiter;
		vector.y *= limiter;
		return vector;
	}
	else {
		return vector;
	}
}
