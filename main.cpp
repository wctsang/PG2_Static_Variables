#include <Novice.h>
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"

const char kWindowTitle[] = "GC1A_09_ソウ_イチョウ";

bool Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Player* player = new Player(640, 360, 20, 10);


	Enemy* enemy[5];

	for (int i = 0; i < 5; i++) {
		enemy[i] = new Enemy(i * 50 + 10, 200, 5, 0, 10, true);
	}

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player->Move(keys, preKeys);

		for (int i = 0; i < 5; i++) {
			if (enemy[i]->isAlive_ == true) {
				enemy[i]->Update();
				enemy[i]->Damage(player->bullet);
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();

		for (int i = 0; i < 5; i++) {
			if (enemy[i]->isAlive_ == true) {
				enemy[i]->Draw();
			}
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
