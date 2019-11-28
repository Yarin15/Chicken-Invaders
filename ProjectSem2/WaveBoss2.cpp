
#include "WaveBoss2.h"
#include "SimpleBossMove.h"
#include "ChickenBoss2.h"


void WaveBoss2::createWave()
{

	std::shared_ptr<ChickenBoss2> newChicken = std::static_pointer_cast<ChickenBoss2>(Factory::create("ChickenBoss2"));
	newChicken->setPosition({ 800.f, 140.f });
	newChicken->SetMoveBehavior(std::make_unique<SimpleBossMove>(newChicken));
	m_chickens.emplace_back(newChicken);

}

