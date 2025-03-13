#pragma once

class Sound
{
public:
	Sound();
	~Sound();

	bool LoadSound(std::string path, bool isLoop);		// 경로값을 받아서 사운드 파일 불러옴, 불러온 파일 반복재생 여부...

	void Play();
	void Stop();

	FMOD::Sound* sound;			// 사운드 파일에 대한 정보
	FMOD::Channel* channel;		// 사운드를 재생시킬 스피커 역할
};