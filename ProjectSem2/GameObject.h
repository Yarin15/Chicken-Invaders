#pragma once
/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include "MacrosEnums.h"
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is a base class for all the objects that exist on the game screen. planty
of methods implemnts here because of the polymorphism. Off course this is an abstract
class.
*/
/////////////////////////////////////////////////////////////////////////////////////////
class GameObject {

public:
	GameObject();
	virtual void draw(sf::RenderWindow& wind);
	bool isInBorder();
	sf::Vector2u getBorderSize() const;
	sf::FloatRect getGlobalBounds() const;
	virtual void moveObj(float, direction) = 0;
	void setRotation(float);
	sf::Vector2f getPosition() const;
	virtual void setPosition(sf::Vector2f pos);
	virtual int getLive() const;
	virtual void decreaseLives();

protected:
	sf::Vector2u windowSize;
	std::unique_ptr <sf::Sprite> Img;
	int m_lives;
};



