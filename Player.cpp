#include"Player.h"
#include"Novice.h"

Player_Class::Player_Class(float posX, float posY, float speedX, float speedY, float radius, int hp, int isAlive)
{
	pos_.x = posX;
	pos_.y = posY;


	speed_.x = speedX;
	speed_.y = speedY;

	radius_ = radius;

	hp_ = hp;

	isAlive_ = isAlive;

	direction_ = 1;

}

Player_Class::~Player_Class()
{
}
//更新
void Player_Class::Update(char* keys, char* preKeys)
{
	//移動
	if (keys[DIK_A]) {
		pos_.x -= speed_.x;
		//方向
		direction_ = -1;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_.x;
		//方向
		direction_ = 1;
	}
	if (keys[DIK_W]) {
		pos_.y -= speed_.y;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_.y;
	}

	//移動上限
	//X
	if (pos_.x <= 0 + radius_) {

		pos_.x = radius_;

	}
	if (pos_.x >= 1280 - radius_) {

		pos_.x = 1280 - radius_;

	}
	//Y
	if (pos_.y <= 0 + radius_) {

		pos_.y = radius_;

	}
	if (pos_.y >= 720 - radius_) {

		pos_.y = 720 - radius_;

	}

	//弾発射
	for (int i = 0; i < max_bullet; i++) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			if (weapons_->GetIsAlive(i) == 0) {//フラグがfalseなら
				weapons_->SetIsAlive(1, i);//フラグをtrueに
				weapons_->SetPos(pos_.x, pos_.y, i);//位置をプレイヤーに
				weapons_->SetSpeed(4, -4, i);//速度を設定
				if (weapons_->GetIsAlive(i) == 1) {//フラグがtrueなら
					break;
				}
			}
		}

		//フラグがtureなら
		if (weapons_->GetIsAlive(i) == 1) {

			weapons_->Update(i);

		}
	}
}


//初期化位置
void Player_Class::SetPos(float posX, float posY)
{

	pos_.x = posX;
	pos_.y = posY;

}
//HP設定
void Player_Class::SetHp(int hp)
{
	hp_ += hp;

	if (hp_ <= 0) {

		hp_ = 0;

	}
}
//初期化HP
void Player_Class::SetInitializationHp(int hp)
{
	hp_ = hp;
}
//フラグ初期化
void Player_Class::SetIsAlive(int alive)
{
	isAlive_ = alive;

}

//描画
void Player_Class::Draw()
{

	//Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawSprite((int)pos_.x - (int)radius_, (int)pos_.y - (int)radius_, image_player, 1, 1, 0.0f, WHITE);
	//弾
	weapons_->Draw();

}
