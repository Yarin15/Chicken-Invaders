#include "Prize.h"

Prize::Prize()
{
	Img = std::move(ResourcesManager::instance().getPicture("prize.png"));
}
