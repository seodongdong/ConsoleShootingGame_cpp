#include "include.h"

// 프로그래밍 언어
// 라이브러리 (stdio.h, stdlib.h, fmod ... 등등 = 다른 사람이 만든 소스코드를 내 소스코드에 넣어주는 것)
// 프레임워크 (콘솔게임, DXUT 등등 프레임워크를 기반으로 프로그램이 동작함. 밑바탕 ...)
// 툴 (유니티, 언리얼, 포토샵 ...)
// API (Window.h, opgg ... 서버의 정보를 가져와서 사용 / 명령)

int main()
{
	Init();

	while (true)
	{
		Update();
		Draw();

		EngineSync(30);
	}

	Release();

	return 0;
}