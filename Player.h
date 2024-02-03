#pragma once
#include"Struct.h"
#include"Weapons.h"
#include"Novice.h"

class Player_Class
{
public:

	Weapons_Class* weapons_ = new Weapons_Class(-100,-100,4,4,10,0,BLUE);

	Player_Class(float posX, float posY, float speedX, float speedY, float radius ,int hp, int isAlive);
	~Player_Class();

	void Update(char* keys, char* preKeys);

	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetRadius() { return radius_; }
	int GetHp() { return hp_; }
	int GetIsAlive() { return isAlive_; }


	void SetPos(float posX, float posY);
	void SetHp(int hp);

	//初期化
	void SetInitializationHp(int hp);

	void SetIsAlive(int alive);

	void Draw();

private:

	VectorFloat2 pos_;

	VectorFloat2 speed_;

	float radius_;

	int hp_;

	int isAlive_;

	int image_player = Novice::LoadTexture("./image/player.png");
};

