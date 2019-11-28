/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "ResourcesManager.h"
#include "RandomFactory.h"

  /////////////////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////// Documentation //////////////////////////////////////

  /*
	This class is an abstract class for falling objects.
	It has no specific implementation for the item on its group.
	The purpose of the class is to give classification for these object whom
	Fall from a chicken after its dead.
  */

  /////////////////////////////////////////////////////////////////////////////////////////

class FallingObject : public GameObject
{
public:
	FallingObject();
	virtual void moveObj(float, direction);
	virtual void emptyFunction() = 0;

protected:
	sf::Vector2f movment;
	sf::Clock deadTimer;
	bool dyingFlag;
	float time;
};

