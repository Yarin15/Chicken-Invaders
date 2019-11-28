#include "WaveBoss3.h"
#include "SimpleBossMove.h"
#include "ChickenBoss3.h"

void WaveBoss3::createWave()
{

	std::shared_ptr<ChickenBoss3> newChicken = std::static_pointer_cast<ChickenBoss3>(Factory::create("ChickenBoss3"));
	newChicken->setPosition({ 800.f, 140.f });
	newChicken->SetMoveBehavior(std::make_unique<SimpleBossMove>(newChicken));
	m_chickens.emplace_back(newChicken);

}
