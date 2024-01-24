#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	posX_ = -100;
	posY_ = -100;
	speedX_ = 10;
	speedY_ = 10;
	radius_ = 10;
	isShot_ = false;
}

void Bullet::Update() {
	posY_ -= speedY_;
}

void Bullet::Draw() {
	if (isShot_ == true) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}