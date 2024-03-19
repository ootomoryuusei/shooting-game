#pragma once
#include"gameChara.h"
#include"CDTIMER.h"
#include"Enemy.h"
#include"Bullet.h"
#include<vector>

using namespace std;



class EnemyMaster :public gameChara
{
	void SetEnemiesRect();
	CDTIMER timer_;
public:
	EnemyMaster();
	~EnemyMaster();
	vector<Enemy*> enemies;
	bool EnemiesAlive() { return true; }
	void InitializeEnemies();
	void UpDate() override;
	void Draw() override;
};

