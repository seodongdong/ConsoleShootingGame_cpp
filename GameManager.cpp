#include "include.h"
#include "Define.h"
// 콘솔프레임에서 관리하던 update, draw를 관리해주는 파일
// 싱글톤 : GameMng 업그레이드
// 유한상태기계 (FSM) : 메뉴화면, 게임화면...
// FMOD : 사운드
// 자료구조 : 스택, 큐, 리스트 구현
// 오브젝트 풀링 업그레이드...

int score = 0;  // 전역 변수 정의
int level = 1;

GameMng::GameMng()
{
	//MenuState* m = new MenuState;
	//CState* p = (CState*)m;

	//stateCtrl.StateAdd(STATE::MENU, new MenuState);	// 다형성...
	//stateCtrl.StateAdd(STATE::GAME, new GameState);

/*	stateCtrl.StateChange(STATE::MENU);*/	// 메뉴 상태로 바뀜

}

GameMng::~GameMng()
{
	system->release();
}

void GameMng::Init()
{
	system = nullptr;
	FMOD::System_Create(&system);
	system->init(512, FMOD_INIT_NORMAL, nullptr);		// channel : 보통 2의 제곱수로 넣어줌


	bool result = backgroundSnd.LoadSound("Sound/backgroundMusic.mp3", true);
	bool result2 = bulletSnd.LoadSound("Sound/bullet.wav", false);

	if (result)
	{
		backgroundSnd.Play();
	}

	stateCtrl.StateChange(new MenuState);
}

void GameMng::Update()
{
	system->update();		// 설정값이 바뀌거나 사운드를 재생시킬 때.
	stateCtrl.Update();
}

void GameMng::Draw()
{
	stateCtrl.Draw();
}

