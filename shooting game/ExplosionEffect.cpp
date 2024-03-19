#include "stdafx.h"
#include "ExplosionEffect.h"

ExplosionEffect::ExplosionEffect(Vec2 _pos)
	:gameChara(_pos)
{
	frames_ = { {EXPLOSION_RECT_SIZE.x * 0,EXPLOSION_RECT_SIZE.y * 0,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 1,EXPLOSION_RECT_SIZE.y * 0,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 2,EXPLOSION_RECT_SIZE.y * 0,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 0,EXPLOSION_RECT_SIZE.y * 1,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 1,EXPLOSION_RECT_SIZE.y * 1,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 2,EXPLOSION_RECT_SIZE.y * 1,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 0,EXPLOSION_RECT_SIZE.y * 2,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 1,EXPLOSION_RECT_SIZE.y * 2,EXPLOSION_RECT_SIZE},
			{EXPLOSION_RECT_SIZE.x * 2,EXPLOSION_RECT_SIZE.y * 2,EXPLOSION_RECT_SIZE} };

	pos_ = _pos;
	speed_ = 0;
	tex_ = TextureAsset(U"EXPLOSION");
	SetCharaRect(EXPLOSION_RECT_SIZE);
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

void ExplosionEffect::Draw()
{
	if (isAlive_) {
		tex_(frames_[frameNum]).resized(EXPLOSION_RECT_SIZE).drawAt(pos_);
		//rect_.drawFrame(1, 1, Palette::Red);
	}
}

void ExplosionEffect::UpDate()
{
	if (CDTimer_.IsTimeOver()) {
		frameNum = (frameNum + 1);
		{
			if (frameNum >= MAX_FRAME_NUM) {
				frameNum = 0;
				DeActivate();
			}
		}
		CDTimer_.ResetTimer();
	}
	else
		CDTimer_.Update();
}

//bool ExplosionEffect::CDTIMER::IsTimeOver()
//{
//	return(CDTimer_ < 0);
//}
//
//void ExplosionEffect::CDTIMER::ResetTimer()
//{
//	CDTimer_ = ANIME_INTERVAL;
//	StartTimer();
//}
//
//void ExplosionEffect::CDTIMER::StartTimer()
//{
//	isTimerRun_ = true;
//}
//
//void ExplosionEffect::CDTIMER::STopTimer()
//{
//	isTimerRun_ = false;
//}
//
//void ExplosionEffect::CDTIMER::Update()
//{
//	if (isTimerRun_)
//		CDTimer_ = CDTimer_ - Scene::DeltaTime();
//}
