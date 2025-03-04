#pragma once
class Player : public Unit	// public(접근제어자) 상속받을 클래스 이름
{
public:
	Player();
	~Player();

	void Update() override;		// 재정의 (부모클래스의 내용과 달라지기 때문에
	void Move() override;
	void Clipping() override;
};