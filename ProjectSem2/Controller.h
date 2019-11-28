/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <SFML\Graphics.hpp>
#include "spaceShip.h"
#include "Level.h"
#include "Menu.h"
#include "MacrosEnums.h"
#include "WaveInterface.h"
#include <sstream>
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is use to manage whole game.
The class is created by the source and it manage the game from it starts to end.
It syncrinize between the menu functions to the levels manager.
The class holds all the objects for each level and syronize it by it manager.
*/

/////////////////////////////////////////////////////////////////////////////////////////
class Controller {
public:
	Controller();
	void playGame();
	void runLevel();

private:
	ResourcesManager & _res;
	std::vector<std::shared_ptr<GameObject>> m_gameObjectVector;
	sf::RenderWindow m_window;
	std::shared_ptr<spaceShip> m_player;
	Level m_level;
	std::vector <std::unique_ptr<WaveInterface>> m_waves;
	size_t levelNum;
	gameStatus m_status;
	Menu m_menu;
	sf::Clock _wavesMovement;
	std::stringstream _stream;

	//Helpers
	void fillWavesVector();
	void gameEnded(std::string, std::string);
	void moveBetweenWaves(size_t);
};

