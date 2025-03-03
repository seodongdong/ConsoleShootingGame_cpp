#include "include.h"

Bullet bullets[D_BULLET_MAX];

Bullet::Bullet()
{
	isAlive = false;
	x = 0;
	y = 0;
	body = '|';
	fColor = GREEN;
	bColor = BLACK;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{

	if (isAlive)
	{
		Move();
		Clipping();
	}


}

void Bullet::Draw()
{
	DrawChar(x, y, body, fColor, bColor);
}

void Bullet::Move()
{
	if (isAlive)
		y--;
}

void Bullet::Clipping()
{
	if (isAlive && y < 0)
		isAlive = false;
}

void Bullet::Enable(int x, int y)
{
	this->x = x;
	this->y = y;
	isAlive = true;
}

void Bullet::Disable()
{
	isAlive = false;
}

void CreateBullet(int x, int y)
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
