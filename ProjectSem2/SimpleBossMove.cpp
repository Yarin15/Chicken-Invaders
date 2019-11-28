#include "SimpleBossMove.h"
#include "ChickenBoss1.h"
#include "ChickenBoss2.h"
#include "ChickenBoss3.h"

SimpleBossMove::SimpleBossMove(std::shared_ptr<ChickenBase> Obj)
	:MoveBehaviorInterface(Obj), lastTimeShot (0.f)
{
	
}

void SimpleBossMove::performMove()
{
	if (numOfMoves < 800 && numOfMoves >= 0)
		//if (object->getPosition().x + object->getGlobalBounds().width < (float)windowSize.x)
	{
		object->move({ 1.f, 0.f });
		numOfMoves -= 1;
	}
	else
	{
		object->move({ -1.f, 0.f });
		numOfMoves -= 1;
		if (numOfMoves == -800)
			numOfMoves = 800;
	}

	if (rotateClock.getElapsedTime().asSeconds() - lastTimeShot > 0.3f)
	{
		object->setRotation((float)(rand() % 110));
		lastTimeShot = rotateClock.getElapsedTime().asSeconds();
	}
}
