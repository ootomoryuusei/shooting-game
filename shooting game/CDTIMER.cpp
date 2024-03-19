#include "stdafx.h"
#include "CDTIMER.h"

bool CDTIMER::IsTimeOver()
{
	return(CDTimer_ < 0);
}

void CDTIMER::ResetTimer()
{
	CDTimer_ = ANIME_INTERVAL;
	StartTimer();
}

void CDTIMER::StartTimer()
{
	isTimerRun_ = true;
}

void CDTIMER::STopTimer()
{
	isTimerRun_ = false;
}

void CDTIMER::Update()
{
	if (isTimerRun_)
	{
		CDTimer_ = CDTimer_ - Scene::DeltaTime();
	}
}
