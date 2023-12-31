#include "SoundManager.h"
#include <iostream>
#include <SDL_mixer.h>
#include <defines.h>

Mix_Chunk* SoundManager::m_backgroundMusic = nullptr;
Mix_Chunk* SoundManager::m_playerColl = nullptr;
Mix_Chunk* SoundManager::cardsSame = nullptr;
Mix_Chunk* SoundManager::cardsNotSame = nullptr;
Mix_Chunk* SoundManager::Success = nullptr;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::init()
{

	std::fstream stream;
	std::string tmp, backgroundMusic, playerColl, cardsSameS, cardsNotSameS, SuccessS;

	stream.open("config\\soundManager.txt");
	stream >> tmp >> backgroundMusic;
	stream >> tmp >> playerColl;
	stream >> tmp >> cardsSameS;
	stream >> tmp >> cardsNotSameS;
	stream >> tmp >> SuccessS;
	stream.close();

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) {
		std::cout << Mix_GetError();

	}

	m_backgroundMusic = Mix_LoadWAV((soundPath + backgroundMusic).c_str());
	m_playerColl = Mix_LoadWAV((soundPath + playerColl).c_str());
	cardsSame = Mix_LoadWAV((soundPath + cardsSameS).c_str());
	cardsNotSame = Mix_LoadWAV((soundPath + cardsNotSameS).c_str());
	Success = Mix_LoadWAV((soundPath + SuccessS).c_str());

	playSound(BACKGROUND_MUSIC);

}

void SoundManager::playSound(SOUND sound)
{
	Mix_AllocateChannels(3);

	

	switch (sound) {
	case BACKGROUND_MUSIC:
		Mix_PlayChannel(0, m_backgroundMusic, 0);
		Mix_Volume(0, 34);
		break;

	case PLAYER_COLLISION:
		Mix_PlayChannel(1, m_playerColl, 0);
		Mix_Volume(0, 24);
		break;

	case CARDS_SAME:
		Mix_PlayChannel(1, cardsSame, 0);
		Mix_Volume(0, 24);
		break;

	case CARDS_NOT_SAME:
		Mix_PlayChannel(1, cardsNotSame, 0);
		Mix_Volume(0, 24);
		break;

	case SUCCESS:
		Mix_PlayChannel(2, Success, 0);
		Mix_Volume(0, 24);
		break;

	
	}



}

void SoundManager::destroy()
{
	Mix_FreeChunk(m_backgroundMusic);
	m_backgroundMusic = nullptr;

	Mix_FreeChunk(m_playerColl);
	m_playerColl = nullptr;
}
