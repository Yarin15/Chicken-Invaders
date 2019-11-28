#include "WantedPositionMove.h"
#include "Chicken.h"


WantedPositionMove::WantedPositionMove(std::shared_ptr<ChickenBase> Obj)
	: MoveBehaviorInterface(Obj)
{
	windowSize = object->getBorderSize();
}
//---------------------------------------------------------------------------//
//The following strategy function moves the chicken to the wanted position
//---------------------------------------------------------------------------//
void WantedPositionMove::performMove()
{
	sf::Vector2f currentPosition = object->getPosition();
	sf::Vector2f wantedPosition = object->getWantedPosition();

	if (wantedPosition.y > currentPosition.y)
		object->move({ 0.f, 1.f });
	else if (wantedPosition.y < currentPosition.y)
		object->move({ 0.f, -1.f });

	if (wantedPosition.x > currentPosition.x)
		object->move({ 1.f, 0.f });
	else if (wantedPosition.x < currentPosition.x)
		object->move({ -1.f, 0.f });

}
