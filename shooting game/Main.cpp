# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include"Player.h"
#include"Enemy.h"
#include"EnemyMaster.h"
#include"Bullet.h"
#include"ExplosionEffect.h"

namespace
{
	int RsetEnemiesNum = EnemyLine * EnemyLines;
}
enum GAMESCENE
{
	TITLE,
	PLAY,
	GAMECLEAR,
	GAMEOVER,
};


void TitleScene(GAMESCENE& scene)
{
	TextureAsset(U"TITLESCENE").resized(Scene::Size()).draw();
	FontAsset(U"TFONT")(U"右クリックでゲームスタート！").drawAt({ Scene::Center().x, Scene::Center().y + FontAsset(U"TFONT").height() }, Palette::Black);
	FontAsset(U"GTFONT")(U"shooting game").drawAt(Scene::Center(), Palette::Black);
}

void PlayScene(GAMESCENE& scene)
{

	TextureAsset(U"PLAYSCENE").resized(Scene::Size()).draw();
}

void GameOverScene(GAMESCENE& scene)
{
	TextureAsset(U"GAMEOVERSCENE").resized(Scene::Size()).draw();
}

void GameClear(GAMESCENE& scene)
{
	TextureAsset(U"GAMECLEARSCENE").resized(Scene::Size()).draw();
}

vector<gameChara*> objList;
void PlayerVSEnemies(Player* player,EnemyMaster* enemyM);
void EnemiesVSPlayer(Bullet* bullet, Player* player);
//void EnemiesBulletVSPlayerBullet(Bullet* pbullet, Bullet* ebullet);

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(Palette::Lightgreen);

	// 太文字のフォントを作成する | Create a bold font with MSDF method
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };

	TextureAsset::Register(U"PLAYER", U"player.png");
	TextureAsset::Register(U"ENEMY", U"enemy.png");
	TextureAsset::Register(U"BULLET", U"bullet.png");
	TextureAsset::Register(U"EXPLOSION", U"explosion.png");
	TextureAsset::Register(U"TITLESCENE", U"titlescene.png");
	TextureAsset::Register(U"PLAYSCENE", U"playscene.png");
	TextureAsset::Register(U"GAMECLEARSCENE", U"clearscene.png");
	TextureAsset::Register(U"GAMEOVERSCENE", U"gameoverscene.jpg");
	FontAsset::Register(U"GTFONT", 50, Typeface::Heavy);
	FontAsset::Register(U"TFONT", 30, Typeface::Heavy);

	//何も引数をかかないと、引数無しのコンストラクタ

	Player* player = nullptr;
	player = new Player;
	player->Initialize();
	objList.push_back(player);

	Enemy* enemy = new Enemy;
	/*enemy->Initialize();*/
	objList.push_back(enemy);

	EnemyMaster* enemyM = new EnemyMaster;
	enemyM->InitializeEnemies();
	objList.push_back(enemyM);

	GAMESCENE gamescene = GAMESCENE::TITLE;

	while (System::Update())
	{
			switch (gamescene)
			{
			case TITLE:
				if (MouseL.down())
				{
					gamescene = GAMESCENE::PLAY;
				}
				break;
			case PLAY:
				if (player->isAlive_ == false)
				{
					gamescene = GAMESCENE::GAMEOVER;
				}
				if (RsetEnemiesNum == 0) {

					gamescene = GAMESCENE::GAMECLEAR;
				}
				break;
			case GAMEOVER:
				gamescene = GAMESCENE::PLAY;
				break;
			case GAMECLEAR:
				if (MouseL.down())
				{
					gamescene = GAMESCENE::TITLE;
				}
					break;
			default:
				gamescene = GAMESCENE::TITLE;
				break;
			}

		switch (gamescene)
		{
		case TITLE:
		{
			TitleScene(gamescene);
			break;
		}
		case PLAY:
		{
			PlayerVSEnemies(player, enemyM);
			EnemiesVSPlayer(enemy->GetBullet(), player);

			for (auto& theI : objList)
			{
				theI->UpDate();
			}
			TextureAsset(U"PLAYSCENE").resized(Scene::Size()).draw();
			for (auto& theI : objList)
			{
				theI->Draw();
			}
			break;
		}
		case GAMECLEAR:
		{
			TextureAsset(U"GAMECLEARSCENE").resized(Scene::Size()).draw();
			break;
		}
		case GAMEOVER:
		{
			break;
		}
		default:
			TitleScene(gamescene);
			break;
		}

		//PlayerVSEnemies(player, enemyM);
		//EnemiesVSPlayer(enemy->GetBullet(), player);
		//for (auto& theI : objList)
		//{
		//	theI->UpDate();
		//}
		///*TextureAsset(U"BGIMAGE").resized(Scene::Size()).draw();*/
		//for (auto& theI : objList)
		//{
		//	theI->Draw();
		//}
	}
	for(auto & theI : objList)
	{
		delete theI;
	}
	objList.clear();
}

void PlayerVSEnemies(Player* player, EnemyMaster* enemyM)
{
	for (auto& theJ : player->GetGunBullet())
	{
		if (!theJ->isActive())
			continue;
		for (auto& theI : enemyM->enemies)
		{
			if (!theI->isActive())
				continue;
			if (theJ->IsMyRectHit(theI->GetCharaRect()))
			{
				ExplosionEffect* explosion = new ExplosionEffect(theI->pos_);
				objList.push_back(explosion);
				theJ->DeActivate();
				theI->DeActivate();
				RsetEnemiesNum--;
			}
		}
	}
}

void EnemiesVSPlayer(Bullet* bullet, Player* player)
{
		if (bullet->isActive() == false)
			return;
		if (bullet->IsMyRectHit(player->GetCharaRect()))
		{
				ExplosionEffect* explosion = new ExplosionEffect(player->pos_);
				objList.push_back(explosion);
				bullet->DeActivate();
				player->DeActivate();
		}
}

//void EnemiesBulletVSPlayerBullet(Player* player, Bullet* ebullet)
//{
//	for (auto& theJ : player->GetGunBullet())
//	{
//		if (!theJ->isActive())
//			continue;
//		if (theJ->IsMyRectHit(ebullet->GetCharaRect()))
//		{
//			ExplosionEffect* explosion = new ExplosionEffect(ebullet->pos_);
//			objList.push_back(explosion);
//			theJ->DeActivate();
//			ebullet->DeActivate();
//		}
//	}
//}
