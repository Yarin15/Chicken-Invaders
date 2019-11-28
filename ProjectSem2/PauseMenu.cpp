#include "PauseMenu.h"
#include "Resume.h"
#include "ExitGame.h"


PauseMenu::PauseMenu(sf::RenderWindow & pauseWindow, sf::RenderWindow & gameWindow)
	:BaseMenu(pauseWindow, ResourcesManager::instance(), PAUSE_MENU_T), _gameWindow(gameWindow)
{
	fillCommandVector();
}

//-------------------------------------------------------------------------------------//
// This function runs the menu.
// The function runs thorugh a pollEvent loop it polls 2 events: closing the
// window, and mouse button released. When a mouseButtonReleased occures, its going
// to the implemented command design pattern and excecute the 
//-------------------------------------------------------------------------------------//
void PauseMenu::run()
{
	sf::Event event;
	while (true)
	{
		while (_window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				_window.close();
				break;
				// Don't let the user resize the pause menu
				case sf::Event::Resized:
				break;
				case sf::Event::MouseButtonReleased:
				handleClick(event);
				return;
			}
		}
		handleTouch();
		draw();
		_window.display();
	}
}

//-------------------------------------------------------------------------------------//
// This function draws all of the menu elements on the screen
//-------------------------------------------------------------------------------------//
void PauseMenu::draw() const
{
	// Drawing the menu only once
	static size_t backgroundDraw = 0;
	if (!backgroundDraw)
		_window.draw(*_res.getPicture("menuBackGround.png"));

	// Draw the elements
	for (auto & text : _m_menuTexts)
		_window.draw(*text);
}
//-------------------------------------------------------------------------------------//
// This function fills the commands vector of the design patterns.
//-------------------------------------------------------------------------------------//
void PauseMenu::fillCommandVector()
{
	_m_commands.emplace_back("Play", std::make_unique<Resume>(_window));
	_m_commands.emplace_back("ExitGame", std::make_unique<ExitGame>(_window));
}
