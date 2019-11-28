#include "Wave3.h"
#include "WantedPositionMove.h"
#include "Chicken.h"

void Wave3::createWave()
{
	for (size_t i = 0; i < 5; i++)
		for (size_t j = 0; j < 10; j++)
		{
			std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
			newChicken->setPosition({ 800.f , 100 * i - 400.f });
			newChicken->setWantedPosition({ 100 * j + 350.f, 100 * i + 100.f });
			newChicken->SetMoveBehavior(std::make_unique<WantedPositionMove>(newChicken));
			m_chickens.emplace_back(newChicken);
		}
}
