#pragma once
#include<vector>
#include"gameChara.h"
#include"Bullet.h"

using namespace std;

const int PLAYER_SIZE = 40;
const double PLAYER_RECT_SIZE = {40};
const double PLAYER_MOVE_SPEED = { PLAYER_SIZE * 4.5 };
const double PLAYER_ATTACK_TIME{ 4.0 }; //爆発の持続時間
const int MAX_PLAYER_FRAME_NUM{ 36 };//アニメのコマ数
//const int PLAYER_MAX_BULLET_NUM{ 5 };

enum direction
{
	UP,LEFT,DOWN,RIGHT,NONE
};

class EnemyMaster;

class Player : public gameChara
{
	vector<Bullet*> Gun_;
	int GetBlankBullet();
	vector<RectF> frames_;
	int frameNum;
public:
	Player();
	/*Player(Vec2 _pos);*/
	~Player();
	void UpDate() override;
	void Draw() override;
	direction GetDirection();
	void Initialize();
	void Release();
	/*bool IsMyRectHit(RectF _rect);*/
	vector<Bullet*> GetGunBullet() { return Gun_; }
};

