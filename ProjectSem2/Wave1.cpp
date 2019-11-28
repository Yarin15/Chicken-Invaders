#include "Wave1.h"
#include "SimpleMove.h"
#include "Chicken.h"

void Wave1::createWave()
{

	for(size_t i = 0; i < 5 ; i++)
		for (size_t j = 0; j < 10; j++)
		{
			std::shared_ptr<Chicken> newChicken = std::static_pointer_cast<Chicken>(Factory::create("Chicken"));
			newChicken->setPosition({ 100 * j + 100.f, 100 * i + 40.f });
			newChicken->SetMoveBehavior(std::make_unique<SimpleMove>(newChicken));
			m_chickens.emplace_back(newChicken);
		}

}
