#include "stdafx.h"
#include "EnemyMaster.h"
#include"Enemy.h"
#include<algorithm>

void EnemyMaster::SetEnemiesRect()
{
	float xmin = Scene::Width(), xmax = 0;
	float ymin = Scene::Height(), ymax = 0;
	for (auto& theI : enemies)
	{
		if (theI->isActive())
		{
			if (xmin > theI->pos_.x)
			{
				xmin = theI->pos_.x;
			}
			if (ymin > theI->pos_.y)
			{
				ymin = theI->pos_.y;
			}
			if (xmax <= theI->pos_.x)
			{
				xmax = theI->pos_.x;
			}
			if (ymax <= theI->pos_.y)
			{
				ymax = theI->pos_.y;
			}
		}
	}


	Vec2 adjustVal = { ENEMY_SIZE / 2, ENEMY_SIZE / 2 };
	myRect_ = { {Vec2{xmin, ymin} - adjustVal}, xmax - xmin + ENEMY_SIZE, ymax - ymin + ENEMY_SIZE };
}

EnemyMaster::EnemyMaster() : gameChara()
{
	SetSpeed(ENEMY_MOVE_SPEED);
}

EnemyMaster::~EnemyMaster()
{
}

//void EnemyMaster::InitializeEnemies()
//{
//	for (int j = 0; j < EnemyLines; j++)
//	{
//		for (int i = 0; i < EnemyLine; i++)
//		{
//			Enemy* enemy = new Enemy;
//			enemies.push_back(enemy);
//		}
//	}
//
//	const int W_MARGIN = { ENEMY_SIZE / 3 };
//	const int H_MARGIN = { ENEMY_SIZE / 10 };
//
//	for (int j = 0; j < EnemyLines; j++)
//	{
//		for (int i = 0; i < EnemyLine; i++)
//		{
//			enemies[j * EnemyLine + i]->speed_ = ENEMY_MOVE_SPEED;
//			enemies[j * EnemyLine + i]->pos_ = Vec2{ i * (ENEMY_SIZE + H_MARGIN),j * (ENEMY_SIZE + W_MARGIN) } + Vec2{ ENEMY_SIZE,ENEMY_SIZE }/2;
//			enemies[j * EnemyLine + i]->isAlive_ = true;
//			enemies[j * EnemyLine + i]->tex_ = TextureAsset(U"ENEMY");
//			enemies[j * EnemyLine + i]->moveDir_ = {1.0,0.0};
//			enemies[j * EnemyLine + i]->SetCharaRect(SizeF{ ENEMY_SIZE,ENEMY_SIZE });
//		}
//
//		speed_ = ENEMY_MOVE_SPEED;
//		SetEnemiesRect();
//		moveDir_ = { 1.0,0.0 };
//	}
//}

void EnemyMaster::InitializeEnemies()
{
	for (int j = 0; j < EnemyLines; j++)
	{
		for (int i = 0; i < EnemyLine; i++)
		{
			Enemy* enemy = new Enemy;
			/*enemy->Initialize();*/
			enemies.push_back(enemy);
			/*Bullet* bullet = nullptr;
			bullet = new Bullet();
			gun_.push_back(bullet);*/
		}
	}

	const int W_MARGIN = { ENEMY_SIZE / 3 };
	const int H_MARGIN = { ENEMY_SIZE / 10 };

	for (int j = 0; j < EnemyLines; j++)
	{
		for (int i = 0; i < EnemyLine; i++)
		{
			enemies[j * EnemyLine + i]->speed_ = ENEMY_MOVE_SPEED;
			enemies[j * EnemyLine + i]->pos_ = Vec2{ i * (ENEMY_SIZE + H_MARGIN),j * (ENEMY_SIZE + W_MARGIN) } + Vec2{ ENEMY_SIZE,ENEMY_SIZE } / 2;
			enemies[j * EnemyLine + i]->isAlive_ = true;
			enemies[j * EnemyLine + i]->tex_ = TextureAsset(U"ENEMY");
			enemies[j * EnemyLine + i]->moveDir_ = { 0.0,1.0 };
			enemies[j * EnemyLine + i]->SetCharaRect(SizeF{ ENEMY_SIZE,ENEMY_SIZE });
		}

		speed_ = ENEMY_MOVE_SPEED;
		SetEnemiesRect();
		moveDir_ = { 0.0,1.0 };
	}
}

//void EnemyMaster::UpDate()
//{
//	const float SWidth = Scene::Width();
//	const float SHeight = Scene::Height();
//	const float WMargin = 50;
//
//
//	if (myRect_.x <= 0 || myRect_.x + myRect_.w >= SWidth - 0)
//	{
//		for (auto& theI : enemies)
//		{
//			theI->FlipMove();
//			theI->MoveDown();
//		}
//	}
//
//	for (auto& theI : enemies)
//		theI->UpDate();
//	SetEnemiesRect();//全体枠（黄色）を再設定
//	
//	if (timer_.IsTimeOver())
//	{
//		int num = Random(0, (int)(enemies.size() - 1));
//		if (enemies[num]->isAlive_==true)
//		{
//			enemies[num]->EnemyShot();
//			
//		}
//		timer_.ResetTimer();
//	}bbb
//	else
//		timer_.Update();
//
//}

void EnemyMaster::UpDate()
{
	const float SWidth = Scene::Width();
	const float SHeight = Scene::Height();
	const float WMargin = 50;


	if (myRect_.y <= 0 || myRect_.y + myRect_.h >= SHeight)
	{
		for (auto& theI : enemies)
		{
			theI->FlipMove();
			theI->MoveDown();
		}
	}

	for (auto& theI : enemies)
		theI->UpDate();
	SetEnemiesRect();//全体枠（黄色）を再設定

	if (timer_.IsTimeOver())
	{
		int num = Random(0, (int)(enemies.size() - 1));
		if (enemies[num]->isAlive_ == true)
		{
			enemies[num]->EnemyShot();

		}
		timer_.ResetTimer();
	}
	else
		timer_.Update();
}

void EnemyMaster::Draw()
{
	for (auto& theI : enemies)
	{
		theI->Draw();
	}
	myRect_.drawFrame(1, 1, Palette::Yellow);
}
