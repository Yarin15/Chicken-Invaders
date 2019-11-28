/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "Factory.h"
#include "RandomFactory.h"
#include "MoveBehaviorInterface.h"
#include "FallingObject.h"

/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////

/*
This class is an abstract class of all enemy kinds.
It controlles all the similar functions and fill it implementaion.
This class can simply use for all other enemys creation just by inheritance this class.
*/

/////////////////////////////////////////////////////////////////////////////////////////

class ChickenBase : public GameObject
{
public:
	virtual void moveObj(float, direction);
	sf::Vector2f getWantedPosition() const;
	void setWantedPosition(sf::Vector2f);
	void move(sf::Vector2f);
	void SetMoveBehavior(std::unique_ptr<MoveBehaviorInterface>);
	virtual std::shared_ptr<GameObject> getDroppedObject() const = 0;
protected:
	sf::Vector2f wantedPosition;
	std::unique_ptr<MoveBehaviorInterface> pMoveBehavior_;
	std::shared_ptr<FallingObject> _dropObject;
};

