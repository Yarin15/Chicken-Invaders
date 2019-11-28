#include "ChickenBoss2.h"



ChickenBoss2::ChickenBoss2()
{
	m_lives = 15;
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("chickenBoss2.png"));
	_dropObject = nullptr;
}

std::shared_ptr<GameObject> ChickenBoss2::getDroppedObject() const
{
	return nullptr;
}
