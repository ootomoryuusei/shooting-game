#pragma once
#include "GameChara.h"
#include"CDTIMER.h"
#include <vector>
using namespace std;

const int EXPLOSION_CHR_SIZE{ 48 }; //がぞうさいず
const SizeF EXPLOSION_RECT_SIZE{ 48, 48 }; //当たり判定用のBBのサイズ
const double EXPLOSION_MOVE_SPEED{ 0 }; //プレイヤーの動作スピード
const double EXPLOSION_EXPLODE_TIME{ 4.0 }; //爆発の持続時間
const int MAX_FRAME_NUM{ 9 };//アニメのコマ数
//const double ANIME_INTERVAL{ 1 / 10.0 };

class ExplosionEffect :
	public gameChara
{
	int frameNum;//今のアニメフレームは何フレーム目？
	/*class CDTIMER {
	public:
		CDTIMER() :CDTimer_(ANIME_INTERVAL), isTimerRun_(true) {}
		double CDTimer_;
		bool IsTimeOver();
		void ResetTimer();
		void StartTimer();
		void STopTimer();
		bool isTimerRun_;
		void Update();
	};*/
	CDTIMER CDTimer_;
	vector<RectF> frames_;
public:
	ExplosionEffect(Vec2 _pos);
	~ExplosionEffect() {}
	void Draw() override;
	void UpDate() override;
};

