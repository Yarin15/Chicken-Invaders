#include "WaveBoss1.h"
#include "SimpleBossMove.h"
#include "ChickenBoss1.h"

void WaveBoss1::createWave()
{

	std::shared_ptr<ChickenBoss1> newChicken = std::static_pointer_cast<ChickenBoss1>(Factory::create("ChickenBoss1"));
	newChicken->setPosition({ 800.f, 140.f });
	newChicken->SetMoveBehavior(std::make_unique<SimpleBossMove>(newChicken));
	m_chickens.emplace_back(newChicken);

}
