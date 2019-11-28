#include "MoveRightAngle1.h"



MoveRightAngle1::MoveRightAngle1(std::shared_ptr<ShootObject> Obj)
	: MoveBulletsInterface(Obj)
{
}

void MoveRightAngle1::performMove()
{
	m_object->move({ 1.f, -4.f });
}
