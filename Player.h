﻿#pragma once
#include"Struct.h"
#include"Weapons.h"
#include"Novice.h"

class Player_Class
{
public:
	//包含
	Weapons_Class* weapons_ = new Weapons_Class(-100,-100,4,4,10,0,BLUE);

	Player_Class(float posX, float posY, float speedX, float speedY, float radius ,int hp, int isAlive);
	~Player_Class();
	//更新
	void Update(char* keys, char* preKeys);
	//ゲッター
	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetRadius() { return radius_; }
	int GetHp() { return hp_; }
	int GetIsAlive() { return isAlive_; }

	//セッター
	void SetPos(float posX, float posY);
	void SetHp(int hp);

	//初期化
	void SetInitializationHp(int hp);
	//フラグ
	void SetIsAlive(int alive);
	//画像
	void Draw();

private:
	//位置
	VectorFloat2 pos_;
	//速度
	VectorFloat2 speed_;
	//半径
	float radius_;
	//HP
	int hp_;
	//フラグ
	int isAlive_;
	//方向
	int direction_;
	//画像
	int image_player = Novice::LoadTexture("./image/player.png");
};

