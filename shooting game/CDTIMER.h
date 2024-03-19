#pragma once

const double ANIME_INTERVAL{ 1 / 10.0 };

class CDTIMER
{
public:
	CDTIMER() :CDTimer_(ANIME_INTERVAL), isTimerRun_(true) {}
	double CDTimer_;
	bool IsTimeOver();
	void ResetTimer();
	void StartTimer();
	void STopTimer();
	bool isTimerRun_;
	void Update();
};

