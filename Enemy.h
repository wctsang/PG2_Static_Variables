#pragma once
#include "Bullet.h"

class Enemy {
protected:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_ = 10;

public:
	static bool isAlive_;
	Enemy(int posX, int posY, int speedX, int speedY, int radius, bool isAlive);
	void Update();
	void Damage(Bullet* bullet);
	void Draw();
};