//---------------------------------------------------------------------------//

#include "spaceShip.h"
#include "AttackFirstLevel.h"
#include "AttackSecondLevel.h"
#include "AttackThirdLevel.h"
#include "AttackFourthLevel.h"
#include "AttackFifthLevel.h"

//---------------------------------------------------------------------------//
//----------------------------------C-tor------------------------------------//
//---------------------------------------------------------------------------//
spaceShip::spaceShip()
	:frameSpeed(500.f), m_score(0), shootLevel(0),
	stPoint({ (float)windowSize.x / 2, (float)windowSize.y - 150.f })
{
	m_lives = 3;
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("ship.png"));
	Img->setPosition(stPoint);
	fillShootsVector();
}
//---------------------------------------------------------------------------//
//The following function fill the shoots vector with the wishes SHOOTS behavior
//that is a part of the stratgy Pattern
//---------------------------------------------------------------------------//
void spaceShip::fillShootsVector()
{
	pAttackBehavior.emplace_back(std::make_unique <AttackFirstLevel>(stPoint));
	pAttackBehavior.emplace_back(std::make_unique <AttackSecondLevel>(stPoint));
	pAttackBehavior.emplace_back(std::make_unique <AttackThirdLevel>(stPoint));
	pAttackBehavior.emplace_back(std::make_unique <AttackFourthLevel>(stPoint));
	pAttackBehavior.emplace_back(std::make_unique <AttackFifthLevel>(stPoint));
}
//---------------------------------------------------------------------------//
//The following function moves the Pacman as the direction leads it as long as
//there is no obstacle, if there is cookie on the way it update the score and
//the speed as the cookie symbolize
//---------------------------------------------------------------------------//
void spaceShip::moveObj(float deltaTime, direction dir)
{
	switch (dir) {
	case LEFT_T: Img->move(-deltaTime * frameSpeed, 0); break;
	case RIGHT_T: Img->move(deltaTime * frameSpeed, 0); break;
	case UP_T: Img->move(0, -deltaTime * frameSpeed); break;
	case DOWN_T: Img->move(0, deltaTime * frameSpeed); break;
	}
}
//---------------------------------------------------------------------------//
//The following function update the user score by the integer it gets
//---------------------------------------------------------------------------//
void spaceShip::setScore(int prize)
{
	m_score += prize;
}
//---------------------------------------------------------------------------//
//The following function restart the data of the spaceShip
//---------------------------------------------------------------------------//
void spaceShip::restart()
{
	resetPosition();
	shootLevel = 0;
	m_score = 0;
	m_lives = 3;
}
//---------------------------------------------------------------------------//
// This function checks if the player has reached a multiplication of of 
// INCREASE_GOAL, every multicplication gives the user extra life.
//---------------------------------------------------------------------------//
void spaceShip::checkAndIncreaseLives()
{
	static int increases = INCREASE_GOAL;
	if (m_score >= increases) {
		m_lives++;
		increases += INCREASE_GOAL;
	}
}
//---------------------------------------------------------------------------//
//The following function gets by refernce the GameObjectsVector, means all
//the objects that presents on the game. it calls to the Attack function of
//the relevat attackBehavior and pass the GameObjectsVector so it can be filled
//with the bullets this function creates
//---------------------------------------------------------------------------//
void spaceShip::makeAttack(std::vector<std::shared_ptr<GameObject>> & objects)
{
	sf::Vector2f thePos = Img->getPosition();//gets the ship position
	//create the relevant attack
	pAttackBehavior[shootLevel]->Attack(objects, 
		{ thePos.x + SHIP_SIZE / 2.f - 6.5f, thePos.y });
}
//---------------------------------------------------------------------------//
//The following function returns the number of lives pacman has
//---------------------------------------------------------------------------//
int spaceShip::getLives() const
{
	return m_lives;
}
//---------------------------------------------------------------------------//
//This function returns the current score of the player
//---------------------------------------------------------------------------//
int spaceShip::getScore() const
{
	return m_score;
}
//---------------------------------------------------------------------------//
//The following function gets a paramter that indicate if there is need to
//improve the attack or lower attack behavior, by this paramter it moves the
//attack behavior to the relevant
//---------------------------------------------------------------------------//
void spaceShip::setAttackBehavior(setAttack attack)
{

	if (attack == INCREASE_T) {
		if (shootLevel + 1 >= pAttackBehavior.size())
			//throw()
			return;
		shootLevel++;
	}
	else
	{
		if (shootLevel == 0)
			return;
		shootLevel--;
	}
}
//---------------------------------------------------------------------------//
// The follwing function resets the space ship position to the starting one.
//---------------------------------------------------------------------------//
void spaceShip::resetPosition()
{
	Img->setPosition(stPoint);
}
