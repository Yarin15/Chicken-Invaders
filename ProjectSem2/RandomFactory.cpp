#include "RandomFactory.h"
#include <time.h>

std::shared_ptr<FallingObject> RandomFactory::create()
{
	// Initiate srand only once
	static int srandInitilizer = 0;
	if (!srandInitilizer) {
		srand((unsigned)time(NULL));
		srandInitilizer++;
	}

	size_t randomize = rand() % 25;
	if (randomize == 24)
		return getVector()[getVector().size()-1].second();
	else 
	{
		randomize = rand() % (getVector().size() - 1);
		if (randomize < 0 || randomize >= getVector().size())
			throw std::out_of_range("Factory Random index Out of Range");
		return getVector()[randomize].second();
	}
}

bool RandomFactory::registerit(const std::string & name, std::shared_ptr<FallingObject>(*f)())
{
	getVector().emplace_back(name, f);
	return true;
}

myVector& RandomFactory::getVector()
{
	static myVector m_vector;
	return m_vector;
}
