#include "ChickenBase.h"



//---------------------------------------------------------------------------//
//The following function moves the object using the strategy design pattern.
//---------------------------------------------------------------------------//
void ChickenBase::moveObj(float deltaTime, direction dir)
{
	pMoveBehavior_->performMove();
}
//---------------------------------------------------------------------------//
// This function literally moves the sprite on the screen
//---------------------------------------------------------------------------//
void ChickenBase::move(sf::Vector2f pos)
{
	Img->move(pos);
}
//---------------------------------------------------------------------------//
// This function set behaviour to the object from the bank of the move
// behaviour inteface
//---------------------------------------------------------------------------//
void ChickenBase::SetMoveBehavior(std::unique_ptr<MoveBehaviorInterface>
	pMoveBehavior)
{
	pMoveBehavior_ = std::move(pMoveBehavior);
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
sf::Vector2f ChickenBase::getWantedPosition() const
{
	return wantedPosition;
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
void ChickenBase::setWantedPosition(sf::Vector2f pos)
{
	wantedPosition = pos;
}
