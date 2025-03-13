#pragma once
class GameMng : public Singleton<GameMng>
{
public:
	GameMng();
	~GameMng();

	CStateCtrl stateCtrl;

	FMOD::System* system;		// FMOD 사운드 매니저
	Sound bulletSnd;
	Sound backgroundSnd;

	void Init();

	void Update();
	void Draw();
};