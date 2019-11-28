#include "ShootObject.h"
#include "ResourcesManager.h"

ShootObject::ShootObject()
{
	m_lives = 1;

}

void ShootObject::initialize(std::unique_ptr<MoveBulletsInterface> newMove, sf::Vector2f pos)
{
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("RedShot.png"));
	Img->setPosition(pos);
	m_bulletMove = std::move(newMove);
}


void ShootObject::move(sf::Vector2f pos)
{
	Img->move(pos);
	if (!isInBorder())
		decreaseLives();
}

void ShootObject::moveObj(float, direction)
{
	m_bulletMove->performMove();
}