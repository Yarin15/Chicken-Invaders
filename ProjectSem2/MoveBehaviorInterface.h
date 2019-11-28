/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is represnt the moveBehaviorInteface movments- means all the class the represnt
kind of move inheritance from this class and fill the necessary function .
THIS IS AN STRATGY PATTERN;
*/
/////////////////////////////////////////////////////////////////////////////////////////
class ChickenBase;

class MoveBehaviorInterface {
public:
	MoveBehaviorInterface(std::shared_ptr<ChickenBase> Obj)
		: object(Obj) {}
	virtual void performMove() = 0;

protected:
	std::shared_ptr<ChickenBase> object;
	sf::Vector2u windowSize;
};

