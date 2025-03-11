#include "include.h"

GameState::GameState()
{
	createEnemyTime = 0;
}

GameState::~GameState()
{
}

void GameState::Start()
{
}

void GameState::Update()
{
	if (GetAsyncKeyState(VK_F2))
	{
		GameMng::GetIns()->stateCtrl.StateChange(new MenuState);
	}

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
		// 20½Ã 10ºÐ 0.5ÃÊ 
		createEnemyTime = GetTickCount() + 100;
		CreateEnemy(rand() & 120, -1);
	}

	BulletEnemyCollision();
}

void GameState::Draw()
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

void GameState::Exit()
{
}

void GameState::BulletEnemyCollision()
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

void GameState::CreateBullet(int x, int y)
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

void GameState::CreateEnemy(int x, int y)
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

void GameState::CreateEffect(int x, int y)
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
