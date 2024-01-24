#pragma once

class Bullet {
public:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_ = 20;
	int radius_;
	bool isShot_ = false;

public:
	Bullet();
	void Update();
	void Draw();
};