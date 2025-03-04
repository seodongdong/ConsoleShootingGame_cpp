#pragma once
class Unit
{
public:		// ���������� : private(�� Ŭ���� �ȿ�����), 
			//	protected(�� Ŭ������ �ڽ� Ŭ�������� ��밡��), public(���� ��밡��) 
	Unit();
	~Unit();

	bool isAlive;		// ������ �״�� ��������.
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;

	virtual void Update();		// virtual = �����Լ�, �ڽ� Ŭ���� �ȿ��� �Լ��� ������ �ٲ㵵 �ȴٴ� ��
	virtual void Draw();

	virtual void Move();
	virtual void Clipping();

	virtual void Enable(int x, int y);
	void Disable();
};