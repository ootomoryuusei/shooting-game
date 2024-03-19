#include "stdafx.h"
#include "gamechara.h"


gameChara::gameChara(Vec2 _pos)
{
	pos_ = _pos;
	moveDir_ = { 0,0 };
	speed_ = 0.0;
	myRect_ = { 0,0,0,0 };
	isAlive_ = false;
}

gameChara::gameChara()
{
	pos_ = { 0,0 };
	moveDir_ = { 0,0 };
	speed_ = 0.0;
	myRect_ = { 0,0,0,0 };
	isAlive_ = false;
}

gameChara::~gameChara()
{
}

void gameChara::SetCharaRect(SizeF _size)
{
	Vec2 adjustVal = { _size.x / 2.0,_size.y / 2.0 };
	myRect_ = { pos_ - adjustVal,_size.x,_size.y };
}

void gameChara::SetPosition(Vec2 _pos)
{
	pos_ = _pos;
}

bool gameChara::IsMyRectHit(RectF _rect)
{
	float wAB = myRect_.w / 2.0 + _rect.w / 2.0;
	float hAB = myRect_.h / 2.0 + _rect.h / 2.0;
	float distx = abs(myRect_.center().x - _rect.center().x);
	float disty = abs(myRect_.center().y - _rect.center().y);
	if (wAB > distx && hAB > disty)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void gameChara::UpDate()
{

}

void gameChara::Draw()
{
	Print << U"GC Draw";
}
