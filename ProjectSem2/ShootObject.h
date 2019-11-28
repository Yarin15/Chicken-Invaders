/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "SFML/Graphics.hpp"
#include "MoveBulletsInterface.h"
#include "GameObject.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*	This is the attack strategy interface.
The class implements an interface for the attacking modes of the player (Spaceship).
The class has an abstract virtual function attack - to shot the mode given
by the client (Player).
*/
/////////////////////////////////////////////////////////////////////////////////////////

class ShootObject : public GameObject {
public:
	ShootObject();
	void initialize(std::unique_ptr<MoveBulletsInterface>, sf::Vector2f);
	void move(sf::Vector2f);
	virtual void moveObj(float, direction);

private:
	std::unique_ptr<sf::Sprite> m_picture;
	std::unique_ptr<MoveBulletsInterface> m_bulletMove;
	static bool m_register;
};