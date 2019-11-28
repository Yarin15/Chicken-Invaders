#include "ChickenBoss3.h"

ChickenBoss3::ChickenBoss3()
{
	m_lives = 15;
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("chickenBoss3.png"));
	_dropObject = nullptr;
}

std::shared_ptr<GameObject> ChickenBoss3::getDroppedObject() const
{
	return nullptr;
}
