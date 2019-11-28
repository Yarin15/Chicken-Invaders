#include "AttackFifthLevel.h"
#include "MoveStraight.h"
#include "MoveLeftAngle1.h"
#include "MoveRightAngle1.h"

//---------------------------------------------------------------------------//
//----------------------------------C-tor------------------------------------//
//---------------------------------------------------------------------------//
AttackFifthLevel::AttackFifthLevel(sf::Vector2f & pos)
	:AttackStrategyInterface(pos)
{
}
//---------------------------------------------------------------------------//
//The following function create the attack that relevant to attack number FIVE
//means it creates 5 diffrent shoot object according to the necessary requires
//---------------------------------------------------------------------------//
void AttackFifthLevel::Attack(std::vector<std::shared_ptr<GameObject>>& obj, 
	sf::Vector2f pos)
{
	//Creating The left shoot
	std::shared_ptr<ShootObject> tempObj1 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj1->initialize(std::make_unique<MoveLeftAngle1>(tempObj1),
		{ pos.x - 25.f, pos.y });
	tempObj1->setRotation(-7);
	obj.emplace_back(tempObj1);

	//Creating The second from left shoot
	std::shared_ptr<ShootObject> tempObj2 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj2->initialize(std::make_unique<MoveLeftAngle1>(tempObj2), 
		{ pos.x - 10.f, pos.y });
	tempObj2->setRotation(-5);
	obj.emplace_back(tempObj2);

	//Creating The center shoot
	std::shared_ptr<ShootObject> tempObj3 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj3->initialize(std::make_unique<MoveStraight>(tempObj3), pos);
	obj.emplace_back(tempObj3);

	//Creating The right shoot
	std::shared_ptr<ShootObject> tempObj4 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj4->initialize(std::make_unique<MoveRightAngle1>(tempObj4), 
		{ pos.x + 10.f, pos.y });
	tempObj4->setRotation(5);
	obj.emplace_back(tempObj4);

	//Creating The second from right shoot
	std::shared_ptr<ShootObject> tempObj5 = 
		std::static_pointer_cast<ShootObject>(Factory::create("RedShot"));
	tempObj5->initialize(std::make_unique<MoveRightAngle1>(tempObj5), 
		{ pos.x + 25.f, pos.y });
	tempObj5->setRotation(7);
	obj.emplace_back(tempObj5);
}
