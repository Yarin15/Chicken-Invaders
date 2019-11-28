/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "MenuCommandInterface.h"
#include "ResourcesManager.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*
This class is the sounds managers class of the game.
Every sound and music to be played, pauses, set Volums, etc Will be found here
The function uses the loaded objects from the resources managers.
The public functions given let the programmer play sounds and music
Whenever he wishes.
The function handleMusic() handle the music in such a way that every odd
time that the function is called the music will stop, for even times, the function
will play the game music again. (It used a static function member)
*/

/////////////////////////////////////////////////////////////////////////////////////////

class SoundManager {

public:
	static SoundManager & instance();
	void handleMusic();
	void pauseGameMusic();
	void playGameMusic();
	void playSound(const std::string &);

private:
	SoundManager();
	SoundManager(const ResourcesManager &) = delete;
	SoundManager operator=(const ResourcesManager &) = delete;
	ResourcesManager & _res;
	std::unique_ptr<sf::Music> _menuMusic;
	std::map<std::string, std::unique_ptr<sf::Sound>> & _soundsMap;
};

