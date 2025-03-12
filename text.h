#pragma once
class Text : public Unit
{
public:
	Text();
	~Text();

	std::string str;	// score
	std::string str2;	// level

	void Draw() override;
};