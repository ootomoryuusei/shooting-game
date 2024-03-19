#include "stdafx.h"
#include "enemy.h"
#include"Bullet.h"

Enemy::Enemy(Vec2 _pos) :gameChara()
{
	pos_ = _pos;
	moveDir_ = { 1,0 };
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	isAlive_ = true;
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE,ENEMY_RECT_SIZE });
	gun_ = new Bullet();
	gun_->SetCharaRect(gun_->tex_.size());
	/*gun_->moveDir_ = { 0,1 };*/
	gun_->moveDir_ = { 1,0 };
	gun_->speed_ = 100.0;
}

Enemy::Enemy() :gameChara()
{
	pos_ = { -800,-800 };
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE,ENEMY_RECT_SIZE });
	moveDir_ = { 1,0 };
	isAlive_ = true;
	gun_ = new Bullet();
	gun_->SetCharaRect(gun_->tex_.size());
	/*gun_->moveDir_ = {0,1};*/
	gun_->moveDir_ = { 1,0 };
	gun_->speed_ = 100.0;
}

Enemy::~Enemy()
{
}

//void Enemy::MoveDown()
//{
//	Vec2 yMoveVec = { 0,ENEMY_SIZE / 4 };
//	pos_ = pos_ + yMoveVec;
//}

void Enemy::MoveDown()
{
	Vec2 xMoveVec = { ENEMY_SIZE / 4 ,0};
	pos_ = pos_ + xMoveVec;
}

void Enemy::EnemyShot()
{
	if (gun_->isActive() == false)
	{
		gun_->SetPosition(pos_);//敵のポジションから発射
		gun_->Activate();
		gun_->SetCharaRect(gun_->tex_.size());
	}
}

void Enemy::UpDate()
{
	if (isAlive_)
	{
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ ENEMY_RECT_SIZE,ENEMY_RECT_SIZE });
	}
	if (gun_->isActive())
		gun_->UpDate();
}

void Enemy::Draw()
{
	if (gun_->isActive())
	{
		gun_->Draw();
		//gun_->rect_.drawFrame(1, 1, Palette::Red);
	}
	if (isAlive_)
	{
		tex_.resized(ENEMY_SIZE).drawAt(pos_);
		myRect_.drawFrame(1, 1, Palette::Red);
	}
}
