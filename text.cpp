#include "include.h"

Text::Text()
{
	str = "SCORE : ";
	isAlive = true;

	str2 = "LEVEL ";
	isAlive = true;
}

Text::~Text()
{
}

void Text::Draw()
{
	if (isAlive)
	{
		std::stringstream ss;
		ss << "SCORE : " << score;  // score 갱신
		str = ss.str();

		DrawStr(x, y, str.c_str(), fColor, bColor);
	}

	if (isAlive)
	{
		std::stringstream ss;
		ss << "LEVEL " << level;  // level 갱신
		str2 = ss.str();

		DrawStr(x, y + 1, str2.c_str(), fColor, bColor);
	}

}
