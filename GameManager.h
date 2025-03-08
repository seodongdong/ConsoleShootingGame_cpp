#pragma once
class GameMng : public Singleton<GameMng>
{
public:
	GameMng();
	~GameMng();

	Player player;			// ¸â¹öº¯¼ö
	Bullet bullets[D_BULLET_MAX];
	Enemy enemys[D_ENEMY_MAX];
	Effect effects[D_EFFECT_MAX];
	Text text;

	DWORD createEnemyTime;

	void Update();
	void Draw();

	void BulletEnemyCollision();

	void CreateBullet(int x, int y);
	void CreateEnemy(int x, int y);
	void CreateEffect(int x, int y);

};