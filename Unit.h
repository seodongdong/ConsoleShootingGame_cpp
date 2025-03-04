#pragma once
class Unit
{
public:		// 접근제어자 : private(내 클래스 안에서만), 
			//	protected(내 클래스와 자식 클래스까지 사용가능), public(어디든 사용가능) 
	Unit();
	~Unit();

	bool isAlive;		// 변수는 그대로 물려받음.
	int x;
	int y;
	char body;
	WORD fColor;
	WORD bColor;

	virtual void Update();		// virtual = 가상함수, 자식 클래스 안에서 함수의 내용을 바꿔도 된다는 뜻
	virtual void Draw();

	virtual void Move();
	virtual void Clipping();

	virtual void Enable(int x, int y);
	void Disable();
};