#include "include.h"
// 콘솔프레임에서 관리하던 update, draw를 관리해주는 파일
// 싱글톤 : GameMng 업그레이드
// 유한상태기계 (FSM) : 메뉴화면, 게임화면...
// FMOD : 사운드
// 자료구조 : 스택, 큐, 리스트 구현
// 오브젝트 풀링 업그레이드...

GameMng::GameMng()
{
	//MenuState* m = new MenuState;
	//CState* p = (CState*)m;

	//stateCtrl.StateAdd(STATE::MENU, new MenuState);	// 다형성...
	//stateCtrl.StateAdd(STATE::GAME, new GameState);

/*	stateCtrl.StateChange(STATE::MENU);*/	// 메뉴 상태로 바뀜

	stateCtrl.StateChange(new MenuState);
}

GameMng::~GameMng()
{
}

void GameMng::Update()
{

	stateCtrl.Update();
}

void GameMng::Draw()
{

	stateCtrl.Draw();
}

