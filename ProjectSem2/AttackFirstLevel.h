/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "AttackStrategyInterface.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*	This is the attack strategy interface.
The class implements an interface for the attacking modes of the player (Spaceship).
The class has an abstract virtual function attack - to shot the mode given
by the client (Player).
*/
/////////////////////////////////////////////////////////////////////////////////////////

class AttackFirstLevel : public AttackStrategyInterface {
public:
	AttackFirstLevel(sf::Vector2f &);
	virtual void Attack(std::vector<std::shared_ptr<GameObject>>&, sf::Vector2f);
};

