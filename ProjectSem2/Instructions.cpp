/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
/////////////////////////////////////// Headers /////////////////////////////////////////

#include "Instructions.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////

//-------------------------------------------------------------------------------------//
// The class c-tor. The class gets all it needs to function.
//-------------------------------------------------------------------------------------//
Instructions::Instructions(sf::RenderWindow & wind, ResourcesManager & resources)
	:_m_window(wind), _res(resources)
{
}

//-------------------------------------------------------------------------------------//
// The implementation of the virtual function. Implementing the command design Pattern.
// The function will show the user the instruction for the game.
//-------------------------------------------------------------------------------------//
void Instructions::execute()
{
	// Display the instructions
	_m_window.draw(*(_res.getPicture("Instructions.png")));
	_m_window.display();

	// Wait for a button to be clicked to finish
	sf::Event Event;
	while (_m_window.waitEvent(Event))
		if (Event.type == sf::Event::KeyPressed)
			break;
	
	// clear the window
	_m_window.clear();
}
//-------------------------------------------------------------------------------------//