#pragma once
class Bullet : public Unit
{
public:
	Bullet();
	~Bullet();

	void Move() override;
	void Clipping() override;	
};