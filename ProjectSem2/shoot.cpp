#include "shoot.h"



shoot::shoot(sf::Vector2f pos)
{
	auto & _res = ResourcesManager::instance();
	Img = std::make_unique <sf::Sprite>(*_res.getPicture("laser.png"));
	Img->setPosition(pos.x + 33.f, pos.y - 67);
}
void shoot::draw(sf::RenderWindow& wind)
{
	wind.draw(*Img);

}
void shoot::moveObj()
{
	Img->move(0.f, -2.f);
}

shoot::~shoot()
{
}
