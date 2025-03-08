#include "include.h"
// 콘솔프레임에서 관리하던 update, draw를 관리해주는 파일
// 싱글톤 : GameMng 업그레이드
// 유한상태기계 (FSM) : 메뉴화면, 게임화면...
// FMOD : 사운드
// 자료구조 : 스택, 큐, 리스트 구현
// 오브젝트 풀링 업그레이드...

GameMng::GameMng()
{
	createEnemyTime = 0;
}

GameMng::~GameMng()
{
}

void GameMng::Update()
{
	player.Update();
	for (int i = 0; i < D_BULLET_MAX; i++)	// Bullet
	{
		bullets[i].Update();
	}


	for (int i = 0; i < D_ENEMY_MAX; i++)	// Enemy
	{
		enemys[i].Update();
	}

	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		effects[i].Update();
	}

	if (createEnemyTime < GetTickCount())
	{
		// 20시 10분 0.5초 
		createEnemyTime = GetTickCount() + 100;
		CreateEnemy(rand() & 120, -1);
	}

	BulletEnemyCollision();
}

void GameMng::Draw()
{
	player.Draw();
	for (int i = 0; i < D_BULLET_MAX; i++)	// Bullet
	{
		bullets[i].Draw();
	}

	for (int i = 0; i < D_ENEMY_MAX; i++)	// Enemy
	{
		enemys[i].Draw();
	}

	for (int i = 0; i < D_EFFECT_MAX; i++)	// Effect
	{
		effects[i].Draw();
	}

	text.Draw();
}

void GameMng::BulletEnemyCollision()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive)
		{
			for (int j = 0; j < D_ENEMY_MAX; j++)
			{
				if (enemys[j].isAlive && bullets[i].x == enemys[j].x &&
					(bullets[i].y == enemys[j].y || bullets[i].y - 1 == enemys[j].y))
				{
					CreateEffect(enemys[j].x, enemys[j].y);		// Effect
					bullets[i].Disable();
					enemys[j].Disable();
					break;
				}
			}
		}
	}
}

void GameMng::CreateBullet(int x, int y)
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (bullets[i].isAlive == false)
		{
			bullets[i].Enable(x, y);
			break;
		}
	}
}

void GameMng::CreateEnemy(int x, int y)
{
	for (int i = 0; i < D_ENEMY_MAX; i++)
	{
		if (enemys[i].isAlive == false)
		{
			enemys[i].Enable(x, y);
			break;
		}
	}
}

void GameMng::CreateEffect(int x, int y)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (effects[i].isAlive == false)
		{
			effects[i].Enable(x, y);
			break;
		}
	}
}
