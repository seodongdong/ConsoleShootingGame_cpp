#pragma once
class Enemy : public Unit
{
public:
	Enemy();
	~Enemy();

	void Move() override;
	void Clipping() override;
};