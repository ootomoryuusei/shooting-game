#include "stdafx.h"
#include "player.h"
#include "Bullet.h"

int Player::GetBlankBullet()
{
	for (int i = 0; i < PLAYER_MAX_BULLET_NUM; i++)
	{
		if (Gun_[i]->isAlive_ == false)
			return i;
	}
	return PLAYER_MAX_BULLET_NUM;
}

Player::Player() : gameChara()
{
	/*pos_ = { Scene::Width() / 2,Scene::Height() / 2 + 200 };*/
	pos_ = { Scene::Width() / 2 + 300,Scene::Height() / 2 };
	moveDir_ = { 0,0 };
	speed_ = 150.0;
	tex_ = TextureAsset(U"PLAYER");
	isAlive_ = true;
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });
}

Player::~Player()
{
}

void Player::UpDate()
{
	if (KeyB.down())
	{
		int num = GetBlankBullet();
		if (num != PLAYER_MAX_BULLET_NUM)
		{
			Gun_[num]->isAlive_ = true;
			Gun_[num]->SetPosition(pos_);
			//ここのpos_はプレイヤーの位置
		}
	}
	for (auto& theI : Gun_)
	{
		theI->UpDate();
		
	}


	direction d = GetDirection();
	/*switch (d)
	{
	case LEFT:
		moveDir_ = { -1.0,0 };
		break;
	case RIGHT:
		moveDir_ = { 1.0,0 };
		break;
	default:
		return;
	}*/
	switch (d)
	{
	case UP:
		moveDir_ = { 0,-1.0 };
		break;
	case DOWN:
		moveDir_ = { 0,1.0 };
		break;
	default:
		return;
	}
	pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });
}

void Player::Draw()
{
	if (isAlive_)
	{
		tex_.resized(PLAYER_SIZE).drawAt(pos_);
		myRect_.drawFrame(1.1, Palette::Red);
	}
	for (auto& theI : Gun_)
	{
		theI->Draw();
	}
}

direction Player::GetDirection()
{
	if (KeyW.pressed() || KeyUp.pressed())
	{
		return UP;
	}
	else if (KeyA.pressed() || KeyLeft.pressed())
	{
		return LEFT;
	}
	else if (KeyS.pressed() || KeyDown.pressed())
	{
		return DOWN;
	}
	else if (KeyD.pressed() || KeyRight.pressed())
	{
		return RIGHT;
	}
	else
	{
		return NONE;
	}
}

void Player::Initialize()
{
	for (int i = 0; i < PLAYER_MAX_BULLET_NUM; i++)
	{
		Bullet* bullet = nullptr;
		bullet = new Bullet();
		Gun_.push_back(bullet);
	}
}

void Player::Release()
{
}
