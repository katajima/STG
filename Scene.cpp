#include"Scene.h"
#include"Novice.h"
#include"math.h"

GameScene_Class::GameScene_Class()
{

	scene_ = Title;


}

GameScene_Class::~GameScene_Class()
{
}
//更新
void GameScene_Class::Update(char* keys, char* preKeys)
{



	switch (scene_)
	{
	case Title:


		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

			scene_ = Game;


			player->SetPos(500, 400);
			player->SetIsAlive(1);
			player->SetInitializationHp(50);
			for (int i = 0; i < max_bullet; i++) {
				player->weapons_->SetIsAlive(0, i);
				player->weapons_->SetPos(-100, -100, i);
				enemy->weapons_->SetIsAlive(0, i);
				enemy->weapons_->SetPos(-100, -100, i);
			}
			enemy->SetInitializationHp(10);
			enemy->SetIsAlive(1);
			enemy->SetPos(400, 100);
			enemy->SetResurrections(3);
			enemy->SetRespawn(120);

		}



		break;
	case Game:


		player->Update(keys, preKeys);
		enemy->Update();

		// プレイヤーと敵の当たり判定処理
		{
			float distX = float(player->GetPosX() - enemy->GetPosX());
			float distY = float(player->GetPosY() - enemy->GetPosY());
			float dist = sqrtf((distX * distX) + (distY * distY));
			float radius = enemy->GetRadius() + player->GetRadius();
			if (dist <= radius) {

				player->SetHp(-1);

			}
		}
		// プレイヤーの弾と敵の当たり判定処理
		{
			for (int i = 0; i < max_bullet; i++) {
				float distX_b = float(player->weapons_->GetPosX(i) - enemy->GetPosX());
				float distY_b = float(player->weapons_->GetPosY(i) - enemy->GetPosY());
				float dist_b = sqrtf((distX_b * distX_b) + (distY_b * distY_b));
				float radius_b = enemy->GetRadius() + player->weapons_->GetRadius();
				if (dist_b <= radius_b && enemy->GetIsAlive() == 1) {

					enemy->SetHp(-1);

					player->weapons_->SetIsAlive(0, i);

					player->weapons_->SetPos(-100, -100, i);
				}

			}
		}
		// 敵の弾とプレイヤーの当たり判定処理
		{
			for (int i = 0; i < max_bullet; i++) {
				float distX_b = float(enemy->weapons_->GetPosX(i) - player->GetPosX());
				float distY_b = float(enemy->weapons_->GetPosY(i) - player->GetPosY());
				float dist_b = sqrtf((distX_b * distX_b) + (distY_b * distY_b));
				float radius_b = player->GetRadius() + enemy->weapons_->GetRadius();
				if (dist_b <= radius_b) {

					player->SetHp(-1);

					enemy->weapons_->SetIsAlive(0, i);

					enemy->weapons_->SetPos(-100, -100, i);
				}

			}
		}
		// プレイヤーの弾とプレイヤーの弾の当たり判定処理
		{
			int k = 0;
			float distX[400];
			float distY[400];
			float dist[400];
			float radius;
			for (int i = 0; i < max_bullet; i++) {
				for (int j = 0; j < max_bullet; j++) {
					if (player->weapons_->GetIsAlive(i) == 1 && player->weapons_->GetIsAlive(j) == 1) {
						if (i == j) {
						}
						else {
							distX[k] = (player->weapons_->GetPosX(i) - player->weapons_->GetPosX(j));
							distY[k] = (player->weapons_->GetPosY(i) - player->weapons_->GetPosY(j));
							dist[k] = sqrtf((distX[k] * distX[k]) + (distY[k] * distY[k]));
							radius = player->weapons_->GetRadius() + player->weapons_->GetRadius();
							if (dist[k] <= radius) {
		
								player->weapons_->SetSpeedR(-1, 1, i);
								player->weapons_->SetSpeedR(1, 1, j);
							}
						}
					}
					k++;		
				}
			}
		}
		//敵の弾と敵の弾の当たり判定処理
		{
			int k = 0;
			float distX[400];
			float distY[400];
			float dist[400];
			float radius;
			for (int i = 0; i < max_bullet; i++) {
				for (int j = 0; j < max_bullet; j++) {
					if (enemy->weapons_->GetIsAlive(i) == 1 && enemy->weapons_->GetIsAlive(j) == 1) {
						if (i == j) {
						}
						else {
							distX[k] = (enemy->weapons_->GetPosX(i) - enemy->weapons_->GetPosX(j));
							distY[k] = (enemy->weapons_->GetPosY(i) - enemy->weapons_->GetPosY(j));
							dist[k] = sqrtf((distX[k] * distX[k]) + (distY[k] * distY[k]));
							radius = enemy->weapons_->GetRadius() + enemy->weapons_->GetRadius();
							if (dist[k] <= radius) {

								enemy->weapons_->SetSpeedR(-1, 1, i);
								enemy->weapons_->SetSpeedR(1, 1, j);
							}
						}
					}
					k++;
				}
			}
		}
		//プレイヤーの弾と敵の弾の当たり判定処理
		{
			int k = 0;
			float distX[400];
			float distY[400];
			float dist[400];
			float radius;
			for (int i = 0; i < max_bullet; i++) {
				for (int j = 0; j < max_bullet; j++) {
					if (player->weapons_->GetIsAlive(i) == 1 && enemy->weapons_->GetIsAlive(j) == 1) {
						if (i == j) {
						}
						else {
							distX[k] = (player->weapons_->GetPosX(i) - enemy->weapons_->GetPosX(j));
							distY[k] = (player->weapons_->GetPosY(i) - enemy->weapons_->GetPosY(j));
							dist[k] = sqrtf((distX[k] * distX[k]) + (distY[k] * distY[k]));
							radius = player->weapons_->GetRadius() + enemy->weapons_->GetRadius();
							if (dist[k] <= radius) {

								player->weapons_->SetSpeedR(1, 1, i);
								enemy->weapons_->SetSpeedR(-1, 1, j);
							}
						}
					}
					k++;
				}
			}
		}








		{
			if (player->GetHp() <= 0) {

				player->SetIsAlive(0);

			}
			if (player->GetIsAlive() == 0) {
				scene_ = GameOver;

			}
		}

		{
			if (enemy->GetHp() <= 0) {

				enemy->SetIsAlive(0);

			}
			if (enemy->GetIsAlive() == 0 && enemy->GetResurrections() <= 0) {
				scene_ = GameClear;

			}
		}

		break;

	case GameOver:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

			scene_ = Title;
			player->SetPos(500, 400);
			player->SetIsAlive(1);
			player->SetInitializationHp(50);
			for (int i = 0; i < max_bullet; i++) {
				player->weapons_->SetIsAlive(0, i);
				player->weapons_->SetPos(-100, -100, i);
				enemy->weapons_->SetIsAlive(0, i);
				enemy->weapons_->SetPos(-100, -100, i);
			}
			enemy->SetInitializationHp(10);
			enemy->SetIsAlive(1);
			enemy->SetPos(400, 100);
			enemy->SetResurrections(3);
			enemy->SetRespawn(120);
		}

		break;
	case GameClear:

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {

			scene_ = Title;
			player->SetPos(500, 400);
			player->SetIsAlive(1);
			player->SetInitializationHp(50);
			for (int i = 0; i < max_bullet; i++) {
				player->weapons_->SetIsAlive(0, i);
				player->weapons_->SetPos(-100, -100, i);
				enemy->weapons_->SetIsAlive(0, i);
				enemy->weapons_->SetPos(-100, -100, i);
			}
			enemy->SetInitializationHp(10);
			enemy->SetIsAlive(1);
			enemy->SetPos(400, 100);
			enemy->SetResurrections(3);
			enemy->SetRespawn(120);
		}



		break;
	}
}
//描画
void GameScene_Class::Draw()
{

	switch (scene_)
	{
	case Title:
		//タイトル
		Novice::DrawSprite(0, 0, image_title, 1, 1, 0.0f, WHITE);
		break;
	case Game:
		//プレイヤー
		player->Draw();
		//敵
		enemy->Draw();

		break;
	case GameOver:
		//ゲームオーバー画面
		Novice::DrawSprite(0, 0, image_over, 1, 1, 0.0f, WHITE);
		break;
	case GameClear:
		//ゲームクリア画面

		Novice::DrawSprite(0, 0, image_clear, 1, 1, 0.0f, WHITE);
		break;
	}

}


