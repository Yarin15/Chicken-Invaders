#include "ChickenLeg.h"


ChickenLeg::ChickenLeg()
{
	Img = std::move(ResourcesManager::instance().getPicture("ChickenLeg.png"));
}
