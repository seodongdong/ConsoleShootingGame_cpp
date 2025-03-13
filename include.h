#include <stdio.h>
#include <Windows.h>	// win32 API
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fmod.hpp>		// cpp 전용

#include "Define.h"
#include "Singleton.h"

#include "Unit.h"		// 플레이어보다 위에서 호출해야함. 밑에 있는 파일들에서 참조해야하기 때문

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect.h"		// 이펙트

#include "Text.h"		// 텍스트

#include "State.h"
#include "StateCtrl.h"

#include "Sound.h"		// 효과음

#include "GameState.h"
#include "MenuState.h"

#include "GameManager.h"		// 항상 맨 밑에 호출해야함. (그래야 인식 가능)

void Init();
void Update();
void Draw();
void Release();

void DrawStr(int x, int y, const char* str, WORD fcolor, WORD bcolor);
void DrawChar(int x, int y, const char c, WORD fcolor, WORD bcolor);
void EngineSync(int fps);
void ClearScreen();
void Flip();