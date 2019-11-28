/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ResourcesManager.h"
#include "MacrosEnums.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////
//-------------------------------------------------------------------------------------//
// The singeltone function of the class. The function creates a static instace
// of the class and returns this. Of course, only one instance can be provided
//-------------------------------------------------------------------------------------//
ResourcesManager & ResourcesManager::instance()
{
	static ResourcesManager _m_instance;
	return _m_instance;
}
//-------------------------------------------------------------------------------------//
// The class c-tor. Initializes all the game resources.
//-------------------------------------------------------------------------------------//
ResourcesManager::ResourcesManager()
	:_menus_texts(2), _scoreBoardTexts(2)
{
	try {
		_menus_texts[0].resize(5);
		_menus_texts[1].resize(2);

		// Load the Font
		_m_font.loadFromFile("Resources/BRLNSR.ttf");

		// Load and design menu Texts
		setMenuTexts();
		setUpdaterTexts();
		loadSprites();
		loadMenuMusic();
		loadSounds();
	}
	catch (std::ios_base::failure & e) {}
}
//-------------------------------------------------------------------------------------//
// This function returns the sounds vector of the game by refernce.
//-------------------------------------------------------------------------------------//
std::map<std::string,std::unique_ptr<sf::Sound>> & ResourcesManager::getSoundsMap()
{
	return _sounds_map;
}
//-------------------------------------------------------------------------------------//
// This function returns the game music.
//-------------------------------------------------------------------------------------//
std::unique_ptr<sf::Music> ResourcesManager::getMenuMusic()
{
	return std::move(_menuMusic);
}
//-------------------------------------------------------------------------------------//
// This function returns the menu texts vector by reference.
//-------------------------------------------------------------------------------------//
std::vector<std::unique_ptr<sf::Text>> & ResourcesManager::getMenuTexts(Menus menuType)
{
	return _menus_texts[menuType];
}
//-------------------------------------------------------------------------------------//
// This function sets the main menu texts, it loads, design and sets their positions.
//-------------------------------------------------------------------------------------//
void ResourcesManager::setMenuTexts()
{

	// This code loads the texts of the main menu 
	_menus_texts[GAME_MENU_T][PLAY_GAME_T] = std::make_unique<sf::Text>("Play Game", _m_font, 120);
	_menus_texts[GAME_MENU_T][TOGGLE_SOUND_T] = std::make_unique <sf::Text>("Toggle Sound", _m_font, 120);
	_menus_texts[GAME_MENU_T][INSTRUCTIONS_T] = std::make_unique<sf::Text>("Instructions", _m_font, 120);
	_menus_texts[GAME_MENU_T][SCORES_T] = std::make_unique <sf::Text>("Scores Board", _m_font, 120);
	_menus_texts[GAME_MENU_T][EXIT_T] = std::make_unique <sf::Text>("EXIT", _m_font, 120);

	_menus_texts[PAUSE_MENU_T][RESUME_T] = std::make_unique<sf::Text>("Resume", _m_font, 60);
	_menus_texts[PAUSE_MENU_T][EXIT_GAME_T] = std::make_unique<sf::Text>("Exit", _m_font, 60);

	// This code set positions to the menu texts
	_menus_texts[GAME_MENU_T][PLAY_GAME_T]->setPosition({ 645.f, 50.f });
	_menus_texts[GAME_MENU_T][TOGGLE_SOUND_T]->setPosition({ 590.f, 250.f });
	_menus_texts[GAME_MENU_T][INSTRUCTIONS_T]->setPosition({ 660.f, 450.f });
	_menus_texts[GAME_MENU_T][SCORES_T]->setPosition({ 610.f, 650.f });
	_menus_texts[GAME_MENU_T][EXIT_T]->setPosition({ 805.f, 850.f });

	_menus_texts[PAUSE_MENU_T][RESUME_T]->setPosition({ 110.f, 100.f });
	_menus_texts[PAUSE_MENU_T][EXIT_GAME_T]->setPosition({ 150.f, 180.f });

	// This code sets color for the menu texts
	for (auto & textVector : _menus_texts)
		for (auto & text : textVector) {
		text->setFillColor(sf::Color::White);
		text->setOutlineThickness(1.f);
		text->setOutlineColor(sf::Color::Black);
	}
}
//-------------------------------------------------------------------------------------//
// This function sets the main menu texts, it loads, design and sets their positions.
//-------------------------------------------------------------------------------------//
std::unique_ptr<sf::Sprite> ResourcesManager::getPicture(std::string sprite_name) const
{
	auto it = _sprites_map.find(sprite_name);
	if (it == _sprites_map.end())
		return nullptr;
	return std::make_unique<sf::Sprite>(it->second);
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
std::vector<std::unique_ptr<sf::Text>> & ResourcesManager::getScoreBoardTexts()
{
	return _scoreBoardTexts;
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
sf::Font & ResourcesManager::getFont()
{
	return _m_font;
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void ResourcesManager::loadSprites()
{
	std::ifstream spritesLoader;
	spritesLoader.open("Sprites.txt");
	if (!spritesLoader.is_open())
		throw std::ios_base::failure("Couldn't Open 'Sprites.txt' file");
	std::string spriteName = "Resources/Images/";
	int indx = 0;

	while (!spritesLoader.eof())
	{
		std::string theName;
		spritesLoader >> theName;
		spriteName += theName;
		std::unique_ptr<sf::Texture> text = std::make_unique<sf::Texture>();
		if (!text->loadFromFile(spriteName))
			throw std::ios_base::failure("Couldn't Open Texture file");
		_texture.emplace_back(std::move(text));
		_sprites_map.emplace(theName, *_texture[indx]);
		spriteName = "Resources/Images/";
		++indx;
	}

	spritesLoader.close();
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void ResourcesManager::loadSounds()
{
	std::ifstream soundsLoader;

	soundsLoader.open("Sounds.txt");
	if (!soundsLoader.is_open())
		throw std::ios_base::failure("Couldn't Open 'Sound.txt' file");
	std::string soundName = "Resources/Sounds/";
	int indx = 0;

	while (!soundsLoader.eof())
	{
		std::string theName;
		soundsLoader >> theName;
		soundName += theName;
		std::unique_ptr<sf::SoundBuffer> buffer = std::make_unique<sf::SoundBuffer>();
		if(!buffer->loadFromFile(soundName))
			throw std::ios_base::failure("Couldn't Open buffer file");
		_soundsBuffer.emplace_back(std::move(buffer));
		_sounds_map.emplace(theName, std::make_unique<sf::Sound>(*_soundsBuffer[indx]));
		soundName = "Resources/Sounds/";
		++indx;
	}
	soundsLoader.close();
}
//-------------------------------------------------------------------------------------//
// This function opens the menu 
//-------------------------------------------------------------------------------------//
void ResourcesManager::loadMenuMusic()
{
	_menuMusic = std::make_unique<sf::Music>();
	if (!_menuMusic->openFromFile("Resources/MenuMusic.ogg"))
		throw std::ios_base::failure("Couldn't Open Music file");
}
//-------------------------------------------------------------------------------------//
void ResourcesManager::setUpdaterTexts()
{
	float x = sf::VideoMode::getDesktopMode().width - 203.f;
	_scoreBoardTexts[0] = std::make_unique<sf::Text>();
	_scoreBoardTexts[1] = std::make_unique<sf::Text>();
	_scoreBoardTexts[0]->setCharacterSize(35);
	_scoreBoardTexts[1]->setCharacterSize(35);
	_scoreBoardTexts[0]->setFont(_m_font);
	_scoreBoardTexts[1]->setFont(_m_font);
	_scoreBoardTexts[0]->setPosition(x, 20.f);
	_scoreBoardTexts[1]->setPosition(x, 80.f);
	_scoreBoardTexts[0]->setFillColor(sf::Color::Yellow);
	_scoreBoardTexts[1]->setFillColor(sf::Color::Yellow);
	_scoreBoardTexts[0]->setOutlineColor(sf::Color::Black);
	_scoreBoardTexts[1]->setOutlineColor(sf::Color::Black);
	_scoreBoardTexts[0]->setOutlineThickness(0.7f);
	_scoreBoardTexts[1]->setOutlineThickness(0.7f);
}