#include "DownRightMove.h"
#include "Chicken.h"

DownRightMove::DownRightMove(std::shared_ptr<ChickenBase> Obj)
	:MoveBehaviorInterface(Obj)
{
	windowSize = Obj->getBorderSize();
}

void DownRightMove::performMove()
{
	sf::Vector2f pos = object->getPosition();

	if (pos.x > windowSize.x || pos.y > windowSize.y)
		object->setPosition(object->getWantedPosition());

	object->move({ 1.f, 1.f });
}


