#include "include.h"

//3차원 배열 값 초기화
char effectBody[3][3][3] =
{
	{
		{' ', ' ', ' '},
		{' ', '*', ' '},
		{' ', ' ', ' '}
	},

	{
		{' ', '*', ' '},
		{'*', '*', '*'},
		{' ', '*', ' '}
	},

	{
		{'*', ' ', '*'},
		{' ', '*', ' '},
		{'*', ' ', '*'}
	}
};

Effect::Effect()
{
	fColor = YELLOW;
	index = 0;
	indexUpdateTime = 0;
}

Effect::~Effect()
{
}

void Effect::Update()
{
	if (isAlive && indexUpdateTime <= GetTickCount())
	{
		index++;
		indexUpdateTime = GetTickCount() + 300;

		if (index >= 3)
		{
			Disable();
		}
	}

	Draw();
}

void Effect::Draw()
{
	if (isAlive)
	{
		DrawChar(x - 1, y - 1, effectBody[index][0][0], fColor, bColor);
		DrawChar(x, y - 1, effectBody[index][0][1], fColor, bColor);
		DrawChar(x + 1, y - 1, effectBody[index][0][2], fColor, bColor);

		DrawChar(x - 1, y, effectBody[index][1][0], fColor, bColor);
		DrawChar(x, y, effectBody[index][1][1], fColor, bColor);
		DrawChar(x + 1, y, effectBody[index][1][2], fColor, bColor);

		DrawChar(x - 1, y + 1, effectBody[index][2][0], fColor, bColor);
		DrawChar(x, y + 1, effectBody[index][2][1], fColor, bColor);
		DrawChar(x + 1, y + 1, effectBody[index][2][2], fColor, bColor);
	}
}

void Effect::Enable(int x, int y)
{
	Unit::Enable(x, y);

	index = 0;
	indexUpdateTime = GetTickCount() + 300;

}
