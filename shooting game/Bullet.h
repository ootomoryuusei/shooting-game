#pragma once
#include"gameChara.h"
#include<vector>

using namespace std;

const int BULLET_SIZE{ 20 };
const int BULLET_RECT_SIZE{ 17 };
const int BULLET_MOVE_SPEED{ 250 };
const int PLAYER_MAX_BULLET_NUM{ 5 };
const Vec2 BULLET_INIT_POS{ 0,-BULLET_SIZE * 2 };

class Bullet : public gameChara
{
	SizeF renderSize_;
	SizeF rectSize_;
public:
	Bullet(Vec2 _pos);
	Bullet(Texture& _tex);
	Bullet();
	void UpDate() override;
	void Draw() override;
};

