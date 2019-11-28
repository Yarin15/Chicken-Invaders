#include "AttackFirstLevel.h"
#include "MoveStraight.h"

//---------------------------------------------------------------------------//
//----------------------------------C-tor------------------------------------//
//---------------------------------------------------------------------------//
AttackFirstLevel::AttackFirstLevel(sf::Vector2f& pos)
	:AttackStrategyInterface(pos)
{
}
//---------------------------------------------------------------------------//
//The following function create the attack that relevant to attack number ONE
//means it creates 1 diffrent shoot object according to the necessary requires
//---------------------------------------------------------------------------//
void AttackFirstLevel::Attack(std::vector<std::shared_ptr<GameObject>>& obj, 
	sf::Vector2f pos)
{
	std::shared_ptr<ShootObject> tempObj = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj->initialize(std::make_unique<MoveStraight>(tempObj), pos);
	obj.emplace_back(tempObj);
}
