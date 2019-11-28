/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ResourcesManager.h"
#include <sstream>
#include "spaceShip.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*
This class is the score board manager.
The class manages the dynamic information of the level, waves, lives, etc...
*/

/////////////////////////////////////////////////////////////////////////////////////////
class LevelUpdater {

public:
	LevelUpdater(sf::RenderWindow &);
	void update(int, int);
	void draw();

private:
	sf::RenderWindow & _window;
	std::string _score;
	std::string _lives;
	std::vector<std::unique_ptr<sf::Text>> & _texts;
	std::stringstream _buffer;
	sf::RectangleShape _rect;
};

