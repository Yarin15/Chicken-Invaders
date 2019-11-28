#include "BaseMenu.h"


BaseMenu::BaseMenu(sf::RenderWindow & window, ResourcesManager & _res, Menus menuType)
	:_window(window), _res(ResourcesManager::instance()), _m_menuTexts(_res.getMenuTexts(menuType)),
	playGameFlag(false)
{
}
//-------------------------------------------------------------------------------------//
// This function gets a command pair as parameter and the the command to the commands
// vector of the menu.
//-------------------------------------------------------------------------------------//
void BaseMenu::addCommand(std::string commandName, std::unique_ptr<MenuCommandInterface> com)
{
	_m_commands.emplace_back(command(commandName, std::move(com)));
}

//-------------------------------------------------------------------------------------//
//The following function handled the touces of the courser with the menu texts
//When a text is marks it'll glow
//-------------------------------------------------------------------------------------//
void BaseMenu::handleTouch()
{
	// Getting the mouse place
	sf::Vector2f mousePlace = ((sf::Vector2f)sf::Mouse::getPosition() -
		(sf::Vector2f) _window.getPosition() +
							   sf::Vector2f(0, -30.f));

	// Loop thorugh the loop and update the texts if needed
	for (auto & text : _m_menuTexts)
		if (text->getGlobalBounds().contains(mousePlace))
		{
			text->setOutlineThickness(7.f);
			text->setOutlineColor(sf::Color(100, 150, 70, 230));
		}

		else
		{
			text->setOutlineThickness(7.f);
			text->setOutlineColor(sf::Color::Black);
		}
}
//-------------------------------------------------------------------------------------//
//The following function handles the user clicks.
//When the user will click on one of the menus option, this funciton will
//check which one of them was clicked and returns this info.
//-------------------------------------------------------------------------------------//
void BaseMenu::handleClick(sf::Event & event)
{
	for (size_t i = 0; i < _m_menuTexts.size(); i++)
		if (_m_menuTexts[i]->getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
			if (i == 0)
				playGameFlag = true;
			_m_commands[i].second->execute();
		}
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//