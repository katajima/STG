#include "Enemy.h"
#include"Novice.h"

Enemy_Class::Enemy_Class(float posX, float posY, float speedX, float speedY, float radius, int hp, int isAlive)
{


	pos_.x = posX;
	pos_.y = posY;

	speed_.x = speedX;
	speed_.y = speedY;

	radius_ = radius;

	hp_ = hp;

	isAlive_ = isAlive;

	respawnCount_ = 120;

	resurrections_ = 3;
}

Enemy_Class::~Enemy_Class()
{
}

void Enemy_Class::SetHp(int hp)
{

	hp_ += hp;

	if (hp_ <= 0) {

		hp_ = 0;

	}

}
//HP初期化
void Enemy_Class::SetInitializationHp(int hp)
{

	hp_ = hp;

}
//フラグ設定
void Enemy_Class::SetIsAlive(int isAlive)
{

	isAlive_ = isAlive;

}
//位置を設定
void Enemy_Class::SetPos(float posX, float posY)
{

	pos_.x = posX;
	pos_.y = posY;

}

void Enemy_Class::SetRespawn(int respawn)
{

	respawnCount_ = respawn;

}
void Enemy_Class::SetResurrections(int resurrections)
{

	resurrections_ = resurrections;

}

//更新
void Enemy_Class::Update()
{

	pos_.x += speed_.x;

	if (pos_.x <= 0 + radius_) {

		pos_.x = radius_;

		speed_.x *= -1;
	}
	if (pos_.x >= 1280 - radius_) {

		pos_.x = 1280 - radius_;
		speed_.x *= -1;
	}

	if (pos_.y <= 0 + radius_) {

		pos_.y = radius_;

	}
	if (pos_.y >= 720 - radius_) {

		pos_.y = 720 - radius_;

	}


	count_bullet++;

	for (int i = 0; i < max_bullet; i++) {
		if (count_bullet >= 120) {
			if (weapons_->GetIsAlive(i) == 0) {
				weapons_->SetIsAlive(1, i);
				weapons_->SetPos(pos_.x, pos_.y, i);
				weapons_->SetSpeed(4, 4, i);
				if (weapons_->GetIsAlive(i) == 1) {
					count_bullet = 0;
					break;
				}
			}
		}

		if (weapons_->GetIsAlive(i) == 1) {

			weapons_->Update(i);

		}
	}


	if(isAlive_ == 0 && resurrections_ > 0){
		respawnCount_--;
		if (respawnCount_ <= 0) {

			isAlive_ = 1;
			hp_ = 30;
			resurrections_ -= 1;
		}
	}

}
//描画
void Enemy_Class::Draw()
{

	//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
	if (isAlive_ == 1) {
		Novice::DrawSprite((int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_, image_enemy, 1, 1, 0.0f, WHITE);
	}
	weapons_->Draw();

}
