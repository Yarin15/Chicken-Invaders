#pragma once
#include <memory>
#include <vector>
#include "ChickenBase.h"
#include "Factory.h"

//forward declaration

class WaveInterface
{
public:
	virtual void createWave() = 0;
	void getWaveStage(std::vector <std::shared_ptr<GameObject>>&);

protected:
	std::vector <std::shared_ptr<ChickenBase>> m_chickens;
};

