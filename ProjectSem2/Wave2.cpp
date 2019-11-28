#include "Wave2.h"
#include "DownRightMove.h"
#include "Chicken.h"

void Wave2::createWave()
{

	for (size_t i = 0; i < 5; i++)
	{
		std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
		newChicken->setPosition({ i * 100.f , ((int)i - 4) * 100.f });
		newChicken->setWantedPosition({ i * 100.f , ((int)i - 4) * 100.f });
		newChicken->SetMoveBehavior(std::make_unique<DownRightMove>(newChicken));
		m_chickens.emplace_back(newChicken);
	}

	for (size_t i = 0; i < 5; i++)
	{
		std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
		newChicken->setPosition({ i * 100.f +200.f , ((int)i - 4) * 100.f });
		newChicken->setWantedPosition({ i * 100.f + 200.f, ((int)i - 4) * 100.f });
		newChicken->SetMoveBehavior(std::make_unique<DownRightMove>(newChicken));
		m_chickens.emplace_back(newChicken);
	}

}