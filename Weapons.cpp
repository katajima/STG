#include"Weapons.h"
#include"Novice.h"

Weapons_Class::Weapons_Class(float posX, float posY, float speedX, float speedY, float radius, int isAlive, unsigned int color)
{
	for (int i = 0; i < max_bullet; i++) {
		pos_[i].x = posX;
		pos_[i].y = posY;

		speed_[i].x = speedX;
		speed_[i].y = speedY;

		radius_ = radius;

		isAlive_[i] = isAlive;

		color_ = color;
	}
}

Weapons_Class::~Weapons_Class()
{
}

void Weapons_Class::SetSpeed(float speedX, float speedY,int count)
{
	
		speed_[count].x = speedX;
		speed_[count].y = speedY;
	

}

void Weapons_Class::SetSpeedR(float speedX, float speedY, int count)
{

	speed_[count].x *= speedX;
	speed_[count].y *= speedY;

}

void Weapons_Class::SetReverseSpeedX(float speedX, int count)
{

	speed_[count].x *= speedX;

}

void Weapons_Class::SetReverseSpeedY(float speedY, int count)
{

	speed_[count].y *= speedY;

}





void Weapons_Class::SetIsAlive(int isAlive ,int count)
{	
		isAlive_[count] = isAlive;
}

void Weapons_Class::SetPos(float posX, float posY,int count)
{

		pos_[count].x = posX;
		pos_[count].y = posY;

}

void Weapons_Class::Update(int count)
{



	
		if (isAlive_[count] == 1) {
			pos_[count].x += speed_[count].x;
			pos_[count].y += speed_[count].y;

			if (pos_[count].x - radius_ <= 0 || pos_[count].x + radius_ >= 1280) {

				speed_[count].x += 0.1f;
				speed_[count].x *= -1;
				if (pos_[count].x - radius_ <= 0) {
					pos_[count].x = radius_;
				}
				if (pos_[count].x + radius_ >= 1280) {
					pos_[count].x = 1280 -radius_;
				}
			}
			if (pos_[count].y - radius_ <= 0 || pos_[count].y + radius_ >= 720) {

				speed_[count].y += 0.1f;

				speed_[count].y *= -1;

				if (pos_[count].y - radius_ <= 0) {
					pos_[count].y = radius_;
				}
				if (pos_[count].y + radius_ >= 720) {
					pos_[count].y = 720 - radius_;
				}
			}
		}
	
}

void Weapons_Class::Draw()
{
	for (int i = 0; i < max_bullet; i++) {
		//Novice::DrawEllipse((int)pos_[i].x, (int)pos_[i].y, (int)radius_, (int)radius_, 0.0f, color_, kFillModeSolid);
		Novice::DrawSprite((int)pos_[i].x - (int)radius_, (int)pos_[i].y - (int)radius_, image_bullet, 1, 1, 0.0f, color_);
	}
}
