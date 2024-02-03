#pragma once
#include"Struct.h"
#include"Weapons.h"
#include"Novice.h"

class Enemy_Class
{
public:
	//包含
	Weapons_Class* weapons_ = new Weapons_Class(-100, -100, 4, 4, 10, 0,RED);

	Enemy_Class(float posX, float posY, float speedX, float speedY, float radius, int hp,int isAlive);
	~Enemy_Class();
	//ゲッター
	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	VectorFloat2 GetSpeed() { return speed_; }
	float GetRadius() { return radius_; }
	int GetHp() { return hp_; }
	int GetIsAlive() { return isAlive_; }

	int GetRespawn() { return respawnCount_; }
	int GetResurrections() { return resurrections_; }

	//セッター
	void SetHp(int hp);
	void SetInitializationHp(int hp);
	void SetIsAlive(int isAlive);
	void SetPos(float posX, float posY);

	void SetRespawn(int respawn);

	void SetResurrections(int resurrections);

	//更新
	void Update();
	//描画
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
	//リスポーンカウント
	int respawnCount_;
	//復活回数
	int resurrections_;
	//クールタイム
	int count_bullet;
	//画像
	int image_enemy = Novice::LoadTexture("./image/enemy.png");
};

