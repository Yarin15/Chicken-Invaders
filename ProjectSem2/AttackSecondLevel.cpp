#include "AttackSecondLevel.h"
#include "MoveStraight.h"

//---------------------------------------------------------------------------//
//----------------------------------C-tor------------------------------------//
//---------------------------------------------------------------------------//
AttackSecondLevel::AttackSecondLevel(sf::Vector2f & pos)
	:AttackStrategyInterface(pos)
{
}
//---------------------------------------------------------------------------//
//The following function create the attack that relevant to attack number TWO
//means it creates 2 diffrent shoot object according to the necessary requires
//---------------------------------------------------------------------------//
void AttackSecondLevel::Attack(std::vector<std::shared_ptr<GameObject>>& obj,
	sf::Vector2f pos)
{
	//creating the left shoot
	std::shared_ptr<ShootObject> tempObj1 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj1->initialize(std::make_unique<MoveStraight>(tempObj1), 
		{ pos.x - 8.f, pos.y });
	obj.emplace_back(tempObj1);

	//creating the right shoot
	std::shared_ptr<ShootObject> tempObj2 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj2->initialize(std::make_unique<MoveStraight>(tempObj2),
		{ pos.x + 8.f, pos.y });
	obj.emplace_back(tempObj2);
}
