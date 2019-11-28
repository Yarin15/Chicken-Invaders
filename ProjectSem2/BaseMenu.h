/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>
#include "MenuCommandInterface.h"
#include "ResourcesManager.h"
#include "MacrosEnums.h"
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////
/*
This is an interface for all menus.
Its is an abstract class that every inheritance class fill its methods by it own kind.
*/
/////////////////////////////////////////////////////////////////////////////////////////
typedef std::pair<std::string, std::unique_ptr<MenuCommandInterface>> command;

class BaseMenu {
public:
	BaseMenu(sf::RenderWindow&, ResourcesManager &, Menus);
	virtual void handleTouch();
	virtual void handleClick(sf::Event &);
	virtual void addCommand(std::string, std::unique_ptr<MenuCommandInterface>);
	virtual void fillCommandVector() = 0;
	virtual void run() = 0;
	virtual void draw() const = 0;

protected:
	std::vector<command> _m_commands;
	sf::RenderWindow & _window;
	ResourcesManager & _res;
	std::vector<std::unique_ptr<sf::Text>> & _m_menuTexts;
	bool playGameFlag;

};

