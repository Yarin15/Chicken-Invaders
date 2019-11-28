/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "MenuCommandInterface.h"
#include "MacrosEnums.h"
#include "SFML/Graphics.hpp"
#include "SoundManager.h"
#include "MenuCommandInterface.h"
#include <string>
#include <memory>
#include "BaseMenu.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class implemnts the BaseMenu when the game starts
the menu paused.
*/
/////////////////////////////////////////////////////////////////////////////////////////

class PauseMenu : public BaseMenu {

public:
	PauseMenu(sf::RenderWindow &, sf::RenderWindow&);
	void run();
	void draw() const;
	void fillCommandVector();

private:
	sf::RenderWindow & _gameWindow;
};

