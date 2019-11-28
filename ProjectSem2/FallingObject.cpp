#include "FallingObject.h"

FallingObject::FallingObject()
	:dyingFlag(true)
{
	m_lives = 1;
	movment.x = 0;
	movment.y = (float) (rand() % 3) + 3;
}

//-------------------------------------------------------------------------------------//
// This is the move function to falling objects (ChickenLeg, Prize and Coin).
// The egg class overrides this function.
//-------------------------------------------------------------------------------------//
void FallingObject::moveObj(float, direction)
{ 
	if (Img->getPosition().y < windowSize.y - 50.f)
		Img->move(movment);
	else
	{
		if (dyingFlag) {
		time = deadTimer.restart().asSeconds();
		dyingFlag = false;
		}
		if(deadTimer.getElapsedTime().asSeconds() > 3.f)
			m_lives = 0;
	}
}