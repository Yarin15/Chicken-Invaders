
/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ChickenBase.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*
This class is represnt the chickenBoss Second object. it is the enemy of the player.
It controlles the movements between all chicken sheets and ovveride the draw function.
This class is an inheritance of chickenbase class.
*/

/////////////////////////////////////////////////////////////////////////////////////////
class ChickenBoss2 : public ChickenBase
{
public:
	ChickenBoss2();
	virtual std::shared_ptr<GameObject> getDroppedObject() const;
private:
	static bool m_register;
};
