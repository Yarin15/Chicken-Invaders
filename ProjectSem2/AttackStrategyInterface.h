/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "SFML/Graphics.hpp"
//#include "ShootObject.h"
#include "GameObject.h"
#include "Factory.h"
#include "ResourcesManager.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*	This is the attack strategy interface. 
The class implements an interface for the attacking modes of the player (Spaceship).
The class has an abstract virtual function attack - to shot the mode given
by the client (Player).
*/
/////////////////////////////////////////////////////////////////////////////////////////

class AttackStrategyInterface {
public:
	AttackStrategyInterface(sf::Vector2f pos) :spaceShipPosition(pos) {}
	virtual void Attack(std::vector<std::shared_ptr<GameObject>>&, sf::Vector2f) = 0;

protected:
	sf::Vector2f spaceShipPosition;
};

