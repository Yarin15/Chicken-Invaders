/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "SoundManager.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////


SoundManager::SoundManager()
	:_res(ResourcesManager::instance()), _soundsMap(_res.getSoundsMap()),
	_menuMusic(std::move(_res.getMenuMusic()))
{
}

//-------------------------------------------------------------------------------------//
// The singeltone function of the class. The function creates a static instace
// of the class and returns this. Of course, only one instance can be provided
//-------------------------------------------------------------------------------------//
SoundManager & SoundManager::instance()
{
	static SoundManager _instance;
	return _instance;
}

//-------------------------------------------------------------------------------------//
// This function handles the game background music. This function is the
// actor of toggle sound button. Using a static variable it knows how many
// times the function was visited and by so know when to stop or play the music.
//-------------------------------------------------------------------------------------//
void SoundManager::handleMusic()
{
	static int iteration = 0;
	iteration % 2 == 0 ? pauseGameMusic() : playGameMusic();
	iteration++;
}
//-------------------------------------------------------------------------------------//
// This function pauses the game background music
//-------------------------------------------------------------------------------------//
void SoundManager::pauseGameMusic()
{
	_menuMusic->pause();
}
//-------------------------------------------------------------------------------------//
// This function plays the game background music. It sets the music to loop
// so when its finished, it starts over.
//-------------------------------------------------------------------------------------//
void SoundManager::playGameMusic()
{
	_menuMusic->play();
	_menuMusic->setLoop(true);
}
//-------------------------------------------------------------------------------------//
// This function gets a name of sounds and plays it from the sounds map
//-------------------------------------------------------------------------------------//
void SoundManager::playSound(const std::string & soundName)
{
	auto it = _soundsMap.find(soundName);
	if (it == _soundsMap.end())
		return;
	
	it->second->play();
}
