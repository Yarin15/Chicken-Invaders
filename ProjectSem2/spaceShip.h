/////////////////////////////////////// Headers /////////////////////////////////////////
#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include "Factory.h"
#include "AttackStrategyInterface.h"
/////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Documentation //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/*
This class is use to manage the spaceShip - means the user Object.
The class is follfiling the player objects methods. 
it moves it according to the user wish, set attack, score according to events on the game.
returns the number of score and lives user have.
*/
/////////////////////////////////////////////////////////////////////////////////////////
class spaceShip : public GameObject
{
public:
	spaceShip();
	int getLives() const;
	int getScore() const;
	void setAttackBehavior(setAttack);
	virtual void moveObj(float, direction);
	void setScore(int);
	void restart();
	void checkAndIncreaseLives();
	void makeAttack(std::vector<std::shared_ptr<GameObject>> &);
	void resetPosition();

private:
	size_t shootLevel;
	int m_score;
	std::vector<std::unique_ptr<AttackStrategyInterface>> pAttackBehavior;
	sf::Clock moveTimer;
	sf::Vector2f stPoint;
	static bool m_register;
	float frameSpeed;

	//Helpers
	void fillShootsVector();

};
