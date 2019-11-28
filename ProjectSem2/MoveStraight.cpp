#include "MoveStraight.h"

MoveStraight::MoveStraight(std::shared_ptr<ShootObject> Obj)
	: MoveBulletsInterface(Obj)
{

}

void MoveStraight::performMove()
{
	m_object->move({ 0.f, -4.f });
}
