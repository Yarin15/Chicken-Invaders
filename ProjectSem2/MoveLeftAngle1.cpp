#include "MoveLeftAngle1.h"


MoveLeftAngle1::MoveLeftAngle1(std::shared_ptr<ShootObject> Obj)
	: MoveBulletsInterface(Obj)
{
}

void MoveLeftAngle1::performMove()
{
	m_object->move({ -1.f, -4.f });
}

