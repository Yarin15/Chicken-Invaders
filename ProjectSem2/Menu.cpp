/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "Menu.h"
#include "ExitGame.h"
#include "Instructions.h"
#include "PlayGame.h"
#include "ToggleSound.h"
#include "ScoreBoard.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////

//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
Menu::Menu(sf::RenderWindow & window, Menus MenuType)
	:BaseMenu(window, ResourcesManager::instance(), MenuType)
{
	fillCommandVector();
	SoundManager::instance().playGameMusic();
}
//-------------------------------------------------------------------------------------//
// This function runs the menu.
// The function runs thorugh a pollEvent loop it polls 2 events: closing the
// window, and mouse button released. When a mouseButtonReleased occures, its going
// to the implemented command design pattern and excecute the 
//-------------------------------------------------------------------------------------//
void Menu::run()
{
	SoundManager::instance().playGameMusic();
	sf::Event event;
	while (!playGameFlag)
	{
		while (_window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				_window.close();
				exit(EXIT_SUCCESS);
				case sf::Event::MouseButtonReleased:
				handleClick(event);
				break;
			}
		}

		_window.clear();
		handleTouch();
		draw();
		_window.display();
	}
	SoundManager::instance().pauseGameMusic();
	playGameFlag = false;
}
//-------------------------------------------------------------------------------------//
// This function draws all of the menu elements on the screen
//-------------------------------------------------------------------------------------//
void Menu::draw() const
{
	// Drawing the menu only once
	static size_t backgroundDraw = 0;
	if (!backgroundDraw)
		_window.draw(*_res.getPicture("menuBackGround.jpg"));

	// Draw the elements
	for (auto & text : _m_menuTexts)
		_window.draw(*text);
}
//-------------------------------------------------------------------------------------//
// This function fills the commands vector of the design patterns.
//-------------------------------------------------------------------------------------//
void Menu::fillCommandVector()
{
	_m_commands.emplace_back("Play", std::make_unique<PlayGame>());
	_m_commands.emplace_back("ToggleSound", std::make_unique<ToggleSound>());
	_m_commands.emplace_back("Instructions", std::make_unique<Instructions>(_window, _res));
	_m_commands.emplace_back("ScoreBoard", std::make_unique<ScoreBoard>(_window));
	_m_commands.emplace_back("ExitGame", std::make_unique<ExitGame>(_window));
}