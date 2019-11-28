#include "AttackThirdLevel.h"
#include "MoveStraight.h"
#include "MoveLeftAngle1.h"
#include "MoveRightAngle1.h"

//---------------------------------------------------------------------------//
//----------------------------------C-tor------------------------------------//
//---------------------------------------------------------------------------//
AttackThirdLevel::AttackThirdLevel(sf::Vector2f & pos)
	:AttackStrategyInterface(pos)
{
}
//---------------------------------------------------------------------------//
//The following function create the attack that relevant to attack number THREE
//means it creates 3 diffrent shoot object according to the necessary requires
//---------------------------------------------------------------------------//
void AttackThirdLevel::Attack(std::vector<std::shared_ptr<GameObject>>& obj, 
	sf::Vector2f pos)
{
	//creating the left shoot
	std::shared_ptr<ShootObject> tempObj1 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj1->initialize(std::make_unique<MoveLeftAngle1>(tempObj1), 
		{ pos.x - 10.f, pos.y });
	tempObj1->setRotation(-5);
	obj.emplace_back(tempObj1);

	//creating the center shoot
	std::shared_ptr<ShootObject> tempObj2 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj2->initialize(std::make_unique<MoveStraight>(tempObj2), pos);
	obj.emplace_back(tempObj2);

	//creating the right shoot
	std::shared_ptr<ShootObject> tempObj3 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj3->initialize(std::make_unique<MoveRightAngle1>(tempObj3),
		{ pos.x + 10.f, pos.y });
	tempObj3->setRotation(5);
	obj.emplace_back(tempObj3);
}
