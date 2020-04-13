#pragma once
#include "Actor.h"
#include "Config.h"

class BackGround : public Actor {
private:
public:
	BackGround() {}
	~BackGround() {}
	void Update() {}
	void Draw();
	void Clean() {}
};

class MidGround : public Actor {
private:
public:
	MidGround() {}
	~MidGround() {}
	void Update() {}
	void Draw();
	void Clean() {}
};

class ForeGround : public Actor {
private:
public:
	ForeGround() {}
	~ForeGround() {}
	void Update() {}
	void Draw();
	void Clean() {}
};

class Platform : public Actor {
private:
public:
	Platform() {}
	~Platform() {}
	void Update();
	void Draw();
	void Clean() {}
};

class Pepper : public Actor {
private:
	int xValue, yValue;
public:
	Pepper();
	~Pepper() {}
	void Update();
	void Draw();
	void Clean() {};
};

class Bullet : public Actor {
private:
public:
	Bullet() { SetObjectType(HAZARD); }
	~Bullet() {}
	void Update();
	void Draw();
	void Clean() {};
};

class Box : public Actor {
private:
public:
	Box() { SetObjectType(HAZARD); }
	~Box() {}
	void Update();
	void Draw();
	void Clean() {};
};