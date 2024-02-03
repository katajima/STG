#pragma once

#include"Player.h"
#include"Enemy.h"

class GameScene_Class
{
public:
	//プレイヤー包含
	Player_Class* player = new Player_Class(500, 500, 5, 5, 20, 0, 1);
	//敵包含
	Enemy_Class* enemy = new Enemy_Class(100, 200, 5, 0, 30, 0, 1);


	GameScene_Class();
	~GameScene_Class();

	


	/// <summary>
	/// 更新
	/// </summary>
	void Update(char * keys,char * preKeys);


	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	//変数
	int scene_;
	//シーン
	enum Scene
	{
		Title,
		Game,
		GameOver,
		GameClear,
	};


};
