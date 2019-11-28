/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesManager.h"
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is use to controll the backGround and scroll it so it will seems that
the objects are moving.
*/

/////////////////////////////////////////////////////////////////////////////////////////
class BackgroundManager
{
public:
	BackgroundManager(sf::RenderWindow&);
	void scrollBackground(sf::Clock&);

private:
	float frameSpeed;
	float frameCounter;
	float switchFrame;
	sf::RenderWindow& m_window;
	std::pair <std::unique_ptr<sf::Sprite>, std::unique_ptr<sf::Sprite>> _gameBackground;
	sf::Clock clock;

	void getBackgroundSprites();
};

