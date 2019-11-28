/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ChickenBase.h"

/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////

/*
This class is represnt the chicken object. it is the enemy of the player.
It controlles the movements between all chicken sheets and ovveride the draw function.
This class is an inheritance of chickenbase class.
*/

/////////////////////////////////////////////////////////////////////////////////////////

class Chicken : public ChickenBase {
public:
	Chicken();
	virtual void draw(sf::RenderWindow&) override;
	virtual std::shared_ptr<GameObject> getDroppedObject() const;
private:
	sf::Clock _spriteSheetClock;
	sf::Vector2u _sheetPos;
	float frameCounter;
	float switchFrame;
	float frameSpeed;
	static bool m_register;
};



