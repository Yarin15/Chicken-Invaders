/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is represnt the MoveBulletsInterface movments - means all the class the represnt
kind of move of bullets that inheritance from this class and fill the necessary function .
THIS IS AN STRATGY PATTERN;
*/
/////////////////////////////////////////////////////////////////////////////////////////

// Forward Declaration
class ShootObject;

class MoveBulletsInterface
{
public:
	MoveBulletsInterface(std::shared_ptr<ShootObject> Obj)
		: m_object(Obj) {};
	virtual void performMove() = 0;

protected:
	std::shared_ptr<ShootObject> m_object;
};

