#pragma once
#include"Struct.h"
#include"Novice.h"

class Weapons_Class
{
public:
	Weapons_Class(float posX, float posY, float speedX, float speedY, float radius,int isAlive,unsigned int color);
	~Weapons_Class();

	float GetPosX(int c) { return pos_[c].x; }
	float GetPosY(int c) { return pos_[c].y; }
	VectorFloat2 GetSpeed(int c) { return speed_[c]; }
	float GetRadius() { return radius_; }
	int GetIsAlive() { return isAlive_[max_bullet]; }
	int GetIsAlive(int c) { return isAlive_[c]; }


	void SetSpeed(float speedX, float speedY,int count);

	void SetSpeedR(float speedX, float speedY, int count);

	void SetReverseSpeedX(float speedX, int count);
	
	void SetReverseSpeedY(float speedY, int count);

	void SetIsAlive(int isAlive, int count);

	void SetPos(float posX, float posY,int count);

	void Update(int count);

	void Draw();

private:
	//位置
	VectorFloat2 pos_[max_bullet];
	//速度
	VectorFloat2 speed_[max_bullet];
	//半径
	float radius_;
	//フラグ
	int isAlive_[max_bullet];
	//色
	unsigned int color_;
	//画像
	int image_bullet = Novice::LoadTexture("./image/bullet.png");
};


