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

	//for (int i = 0; i < gameobjects.size(); i++)
	//{
	//	gameobjects[i]->Update;
	//}

	if (createEnemyTime < GetTickCount())
	{
		// 20시 10분 0.5초 
		createEnemyTime = GetTickCount() + 100;
		CreateEnemy(rand() & 120, 0);
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

	//for (int i = 0; i < bullets.size(); i++)
	//{
	//	bullets[i]->Draw();
	//}

	for (int i = 0; i < D_ENEMY_MAX; i++)	// Enemy
	{
		enemys[i].Draw();
	}

	for (int i = 0; i < D_EFFECT_MAX; i++)	// Effect
	{
		effects[i].Draw();
	}

	//for (int i = 0; i < gameobjects.size(); i++)
	//{
	//	gameobjects[i]->Draw;
	//}

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

					score++;
					if (score == 150)
					{
						level++;
					}
					if (score == 300)
					{
						level++;
					}
					
					break;
				}
			}
		}
	}

	//for (int i = 0; i < bullets.size(); i++)
	//{
	//	if (bullets[i]->isAlive)
	//	{
	//		for (int j = 0; j < enemys.size(); j++)
	//		{
	//			if (enemys[j]->isAlive && bullets[i]->x == enemys[j]->x &&
	//				(bullets[i]->y == enemys[j]->y || bullets[i]->y - 1 == enemys[j]->y))
	//			{
	//				CreateEffect(enemys[j]->x, enemys[j]->y);		// Effect
	//				bullets[i]->Disable();
	//				enemys[j]->Disable();
	//				
	//				break;
	//			}
	//		}
	//	}
	//}
}

void GameState::CreateBullet(int x, int y)
{
	int bulletsCount = 1;	// 총알 개수

	if (level == 1)
		bulletsCount = 1;
	else if (level == 2)
		bulletsCount = 2;
	else if (level == 3)
		bulletsCount = 3;

	int created = 0;	// 생성된 총알 개수

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		//bullets.push_back(new Bullet());
		//bullets[i]->x = 10;
		

		if (!bullets[i].isAlive)
		{
			// 각 총알 좌표 위치 조정
			if (level == 1)
			{
				bullets[i].Enable(x, y);
				GameMng::GetIns()->bulletSnd.Play();
			}     
			else if (level == 2)
			{
				if (created == 0)
				{
					bullets[i].Enable(x - 1, y);
					GameMng::GetIns()->bulletSnd.Play();
				}
				else if (created == 1)
				{
					bullets[i].Enable(x + 1, y);
					//GameMng::GetIns()->bulletSnd.Play();
				}
			}
			else if (level == 3)
			{
				if (created == 0)
				{
					bullets[i].Enable(x - 1, y);
					GameMng::GetIns()->bulletSnd.Play();
				}
				else if (created == 1)
				{
					bullets[i].Enable(x, y);
					//GameMng::GetIns()->bulletSnd.Play();
				}
				else if (created == 2)
				{
					bullets[i].Enable(x + 1, y);
					//GameMng::GetIns()->bulletSnd.Play();
				}

			}

			created++;

			if (created >= bulletsCount)	// 생성된 총알 개수가 총알 개수보다 많으면
				return;
		}
	}

	//for (int i = 0; i < bullets.size(); i++)
	//{
	//	if (bullets[i]->isAlive == false)
	//	{
	//		bullets[i]->Enable(x, y);
	//		return;
	//	}
	//}

	//Bullet* bullets = new Bullet();
	//bullet->Enable(x,y);
	//bullets.push_back(bullet);
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

	//for (int i = 0; i < enemys.size(); i++)
	//{
	//	if (enemys[i]->isAlive == false)
	//	{
	//		enemys[i]->Enable(x, y);
	//		break;
	//	}
	//}

	//Enemy* enemys = new Enemy();
	//enemy->Enable(x,y);
	//enemys.push_back(enemy);
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

	//for (int i = 0; i < effects.size(); i++)
	//{
	//	if (effects[i]->isAlive == false)
	//	{
	//		effects[i]->Enable(x, y);
	//		break;
	//	}
	//}

	//Effect* effects = new Effect();
	//effect->Enable(x,y);
	//effects.push_back(effect);
}

	//void CreateObject(ID id, int x, int y);
	//{
	//	if (id == ID::NONE)
	//	{
	//		return;
	//	}

	//	for (int i = 0; i < gameobjects.size(); i++)
	//	{
	//		if (gameobjects[i]->id == id && gameobjects[i]->isAlive == false)
	//		{
	//			gameobjects[i]->Enable(x, y);
	//			
	//			return;
	//		}
	//	}

	//	switch (id)
	//	{
	//	case BULLET:
	//		unit = new Bullet();
	//		break;
	//	
	//	case ENEMY;
	//		unit = new ENEMY();
	//		break;

	//	case EFFECT;
	//		unit = new EFFECT();
	//		break;
	//	}
	//

	// if (unit)
	// {
	//		unit -> Enable(x, y);
	//		gameobjects.push_back();
	// }