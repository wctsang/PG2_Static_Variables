#include "Novice.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(int posX, int posY, int radius, int speed) {
	posX_ = posX;
	posY_ = posY;
	radius_ = radius;
	speed_ = speed;
}


void Player::Move(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	for (int i = 0; i < 10; i++) {
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && bullet[i].isShot_ == false) {
			bullet[i].posX_ = posX_;
			bullet[i].posY_ = posY_;
			bullet[i].radius_ = 10;
			bullet[i].isShot_ = true;
			break;
		}
		if (bullet[i].isShot_ == true) {
			bullet[i].Update();

		}
	}
	for (int i = 0; i < 10; i++) {
		if (bullet[i].posY_ < -20) {
			bullet[i].isShot_ = false;
		}
	}
}


void Player::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	for (int i = 0; i < 10; i++) {
		if (bullet[i].isShot_ == true) {
			bullet[i].Draw();
		}
	}
}




Player::~Player() {

}