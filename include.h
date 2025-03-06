#include <stdio.h>
#include <Windows.h>	//win32 API
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include "Define.h"
#include "Singleton.h"

#include "Unit.h"		// �÷��̾�� ������ ȣ���ؾ���. �ؿ� �ִ� ���ϵ鿡�� �����ؾ��ϱ� ����

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Effect.h"
#include "Text.h"


#include "GameManager.h"		// �׻� �� �ؿ� ȣ���ؾ���. (�׷��� �ν� ����)

void Init();
void Update();
void Draw();
void Release();

void DrawStr(int x, int y, const char* str, WORD fcolor, WORD bcolor);
void DrawChar(int x, int y, const char c, WORD fcolor, WORD bcolor);
void EngineSync(int fps);
void ClearScreen();
void Flip();