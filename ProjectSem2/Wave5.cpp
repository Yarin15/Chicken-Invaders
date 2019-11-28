#include "Wave5.h"
#include "WantedPositionMove.h"
#include "Chicken.h"

void Wave5::createWave()
{
	for (size_t i = 0; i < 5; i++)
	{
		std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
		newChicken->setWantedPosition({ i * 100.f + 300.f, ((float)i) * 100.f + 300.f});
		newChicken->setPosition({ i * 100.f , ((int)i - 4) * 100.f });
		newChicken->SetMoveBehavior(std::make_unique<WantedPositionMove>(newChicken));
		m_chickens.emplace_back(newChicken);
	}

	for (size_t i = 0; i < 5; i++)
	{
		std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
		newChicken->setWantedPosition({ i * 100.f + 700.f, ((float)i) * 100.f + 300.f});
		newChicken->setPosition({ i * 900.f , ((int)i - 4) * 100.f });
		newChicken->SetMoveBehavior(std::make_unique<WantedPositionMove>(newChicken));
		m_chickens.emplace_back(newChicken);
	}
}
