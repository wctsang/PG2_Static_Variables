#pragma once
#include "Bullet.h"

class Player {
public:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
	Bullet bullet[10];

	Player(int posX, int posY, int radius, int speed);
	void Move(char* keys, char* preKeys);
	void Draw();
	~Player();
};
