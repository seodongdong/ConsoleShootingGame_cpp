#pragma once
class GameMng : public Singleton<GameMng>
{
public:
	GameMng();
	~GameMng();

	CStateCtrl stateCtrl;

	void Update();
	void Draw();
};