#pragma once
class Player : public Unit	// public(����������) ��ӹ��� Ŭ���� �̸�
{
public:
	Player();
	~Player();

	void Update() override;		// ������ (�θ�Ŭ������ ����� �޶����� ������
	void Move() override;
	void Clipping() override;
};