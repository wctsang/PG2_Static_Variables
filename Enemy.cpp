#include "Enemy.h"
#include "Player.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY, int radius,  bool isAlive) {
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = radius;
	isAlive_ = isAlive;
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Damage(Bullet* bullet) {
	int a = posX_ - bullet->posX_;
	int b = posY_ - bullet->posY_;
	if (((a * a) + (b * b)) < (radius_ + bullet->radius_) * (radius_ + bullet->radius_)) {
		isAlive_ = false;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
}