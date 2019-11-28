/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ExitGame.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////

ExitGame::ExitGame(sf::RenderWindow & wind)
	:_window(wind)
{
}

//-------------------------------------------------------------------------------------//
// The implementation of the virtual function. Implementing the command design Pattern.
// The function will exit the game and the program.
//-------------------------------------------------------------------------------------//
void ExitGame::execute()
{
	_window.clear();
	
	// Create the text and the screen shadow.
	auto & _res = ResourcesManager::instance();
	sf::Text exitText("Thank you for playing!\n           Exiting...", _res.getFont(), 150);
	sf::RectangleShape rect({ (float)_window.getSize().x, (float)_window.getSize().y });
	ShadowAndShowText(rect, exitText);

	// Define a timer
	sf::Clock timer;

	_window.clear();
	_window.draw(rect);
	_window.draw(exitText);
	_window.display();

	// Exit only when 4 second have passed.
	while (!(timer.getElapsedTime().asSeconds() > 3));
	_window.close();
	exit(EXIT_SUCCESS);
}
//-------------------------------------------------------------------------------------//
// This is an helper function to set the exit text and to shadow the screen before exit.
//-------------------------------------------------------------------------------------//
void ExitGame::ShadowAndShowText(sf::RectangleShape & rect, sf::Text & exitText)
{
	exitText.setFillColor(sf::Color::White);
	exitText.setOutlineThickness(2.f);
	exitText.setOutlineColor(sf::Color::Magenta);
	exitText.setPosition(300.f, 400.f);
	rect.setFillColor(sf::Color(0, 0, 0, 150));
}