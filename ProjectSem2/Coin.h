/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "FallingObject.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class inheritance from FallingObject and represnt the coin;
Off course it implemts all the necessary functions to this class
*/
/////////////////////////////////////////////////////////////////////////////////////////
class Coin : public FallingObject {
public:
	Coin();
	virtual void emptyFunction() {}
	void draw(sf::RenderWindow &) override;

private:
	static bool _randomRegister;
	sf::Clock _spriteSheetClock;
	sf::Vector2u _sheetPos;
	float _frameCounter;
	float _switchFrame;
	float _frameSpeed;
};

