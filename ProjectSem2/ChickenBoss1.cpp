#include "ChickenBoss1.h"


ChickenBoss1::ChickenBoss1()
{
	m_lives = 15;
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("chickenBoss1.png"));
	_dropObject = nullptr;
}

std::shared_ptr<GameObject> ChickenBoss1::getDroppedObject() const
{
	return nullptr;
}
