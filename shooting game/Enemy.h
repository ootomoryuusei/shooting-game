#pragma once
#include"gameChara.h"
#include"Bullet.h"
#include"CDTIMER.h"
#include<vector>


const int ENEMY_SIZE = 48;
const int EnemyLine = 8;
const int EnemyLines = 5;
const int EnemyNum = { EnemyLine * EnemyLines };
const double ENEMY_MOVE_SPEED = { ENEMY_SIZE / 2 };
const double ENEMY_RECT_SIZE = { 45.0 };
const double ENEMY_BULLET_RECT_SIZE{ 17.0 };



class Enemy : public gameChara
{
	Bullet* gun_;
public:
	Enemy(Vec2 _pos);
	Enemy();
	~Enemy();
	/*void Initialize();*/
	void FlipMove() { moveDir_ = -moveDir_; }
	void MoveDown();
	void EnemyShot();
    Bullet* GetBullet() { return(gun_); }
	void UpDate() override;
	void Draw() override;
};

