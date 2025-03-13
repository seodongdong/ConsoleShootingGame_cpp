#include "include.h"

Sound::Sound()
{
	sound = nullptr;
	channel = nullptr;
}

Sound::~Sound()
{
}

bool Sound::LoadSound(std::string path, bool isLoop)
{
	if (GameMng::GetIns()->system != nullptr)
	{
		FMOD_MODE mode = isLoop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;

		FMOD_RESULT result = GameMng::GetIns()->system->
			createSound(path.c_str(), mode, nullptr, &sound);

		return result == FMOD_OK;
	}
	else
	{
		return false;
	}
}

void Sound::Play()
{
	if (sound != nullptr && GameMng::GetIns()->system)
	{
		GameMng::GetIns()->system->playSound(sound, nullptr, false, &channel);
	}
}

void Sound::Stop()
{
	if (channel != nullptr)
	{
		channel->stop();
	}
}
