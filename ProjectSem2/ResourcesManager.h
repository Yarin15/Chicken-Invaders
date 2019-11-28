/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "MenuCommandInterface.h"
#include <map>
#include <memory>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "MacrosEnums.h"
#include <SFML/Audio.hpp>
#include <exception>

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This Class is singletone class, and therefore the copy c-tor and operator = are deleted.
This Class manages all the  resources of the game: Sprites, Pictures,
Music, Backgrounds, etc...
At the first time that the instance function will be called the class
will load all of the resources that the game need.
The class supplies getter for the resources.
Some of the attributes are pointers, to not passing big objects to slow the game.
*/
/////////////////////////////////////////////////////////////////////////////////////////

typedef std::pair<std::string, std::shared_ptr<sf::Sprite>(*)(sf::Texture&)> textures;

class ResourcesManager {

public:
	// Getters
	std::map<std::string, std::unique_ptr<sf::Sound>> & getSoundsMap();
	std::vector<std::unique_ptr<sf::Text>> & getMenuTexts(Menus);
	std::unique_ptr<sf::Music> getMenuMusic();
	std::unique_ptr<sf::Sprite> getPicture(std::string) const;
	std::vector<std::unique_ptr<sf::Text>> & getScoreBoardTexts();
	sf::Font & getFont();
	static ResourcesManager & instance();


private:
	ResourcesManager();
	ResourcesManager(const ResourcesManager &) = delete;
	ResourcesManager operator=(const ResourcesManager &) = delete;

	sf::Font _m_font;
	std::vector<std::unique_ptr<sf::SoundBuffer>> _soundsBuffer;
	std::map<std::string, std::unique_ptr<sf::Sound>> _sounds_map;
	std::unique_ptr<sf::Music> _menuMusic;
	std::vector<std::unique_ptr<sf::Text>> _scoreBoardTexts;
	std::vector<std::vector<std::unique_ptr<sf::Text>>> _menus_texts;
	std::vector<std::unique_ptr<sf::Texture>> _texture;
	std::map<std::string, sf::Texture&> _sprites_map;

	// Loaders
	void setMenuTexts();
	void setUpdaterTexts();
	void loadSprites();
	void loadSounds();
	void loadMenuMusic();
};