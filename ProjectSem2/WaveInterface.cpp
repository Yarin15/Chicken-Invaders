#include "WaveInterface.h"

void WaveInterface::getWaveStage(std::vector <std::shared_ptr<GameObject>>& m_objects)
{
	for (auto & chicken : m_chickens)
		m_objects.emplace_back(chicken);
}