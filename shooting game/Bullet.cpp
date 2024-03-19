#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vec2 _pos)
{
	pos_ = _pos;
	speed_ = BULLET_MOVE_SPEED;
	tex_ = TextureAsset(U"BULLET");
	SetCharaRect(SizeF{ BULLET_RECT_SIZE,BULLET_RECT_SIZE });
	/*moveDir_ = { 0,-1 };*/
	moveDir_ = { -1,0 };
	isAlive_ = true;
}

Bullet::Bullet(Texture& _tex)
{
	pos_ = BULLET_INIT_POS;
	speed_ = BULLET_MOVE_SPEED;
	tex_ = _tex;
	SetCharaRect(SizeF{ BULLET_RECT_SIZE,BULLET_RECT_SIZE });
	/*moveDir_ = { 0,-1 };*/
	moveDir_ = { -1,0 };
	isAlive_ = false;
}

Bullet::Bullet()
{
	pos_ = BULLET_INIT_POS;
	speed_ = BULLET_MOVE_SPEED;
	tex_ = TextureAsset(U"BULLET");
	SetCharaRect(SizeF{ BULLET_RECT_SIZE,BULLET_RECT_SIZE });
	/*moveDir_ = { 0,-1 };*/
	moveDir_ = { -1,0 };
	isAlive_ = true;

}

void Bullet::UpDate()
{
	if (isAlive_)
	{
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ BULLET_SIZE, BULLET_SIZE });
		if (IsMyRectHit(RectF({ 0,0 }, { Scene::Width(), Scene::Height() })) == false)
		{
			pos_ = BULLET_INIT_POS;
			DeActivate();
		}
	}
	else
		return;
	/*if (pos_.y < 0)
	{
		isAlive_ = false;
		pos_ = BULLET_INIT_POS;
	}
	if (pos_.y > 600)
	{
		isAlive_ = false;
	    pos_ = BULLET_INIT_POS;
	}*/
	if (pos_.x < 0)
	{
		isAlive_ = false;
		pos_ = BULLET_INIT_POS;
	}
	if (pos_.x > 800)
	{
		isAlive_ = false;
		pos_ = BULLET_INIT_POS;
	}
}

void Bullet::Draw()
{
	if (isAlive_)
	{
		tex_.resized(BULLET_SIZE).drawAt(pos_);
		myRect_.drawFrame(1, 1, Palette::Red);
	}
}
