
/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include <SFML\Graphics.hpp>
#include "MacrosEnums.h"
#include "spaceShip.h"
#include "Factory.h"
#include <memory>
#include "Chicken.h"
#include "ChickenBoss1.h"
#include "ChickenBoss2.h"
#include "ChickenBoss3.h"
#include "CollisionHandling.h"
#include "BackgroundManager.h"
#include "ShootObject.h"
#include "LevelUpdater.h"
#include "Egg.h"
#include "Logger.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is use to manage each level.
The class is created by the controller and each time it need to run a new level
after the grid of the level created and the level class holds it by refernce
it intialize the dynamic objects and the starts the loop game-means the user
can start to play and press the direction keys and the Chickens do their moves.
So according to that the level manage the SHIP and the CHICKENS movements and
also manage the collision between them.
*/

/////////////////////////////////////////////////////////////////////////////////////////

class Level {
public:
	Level(sf::RenderWindow&, std::vector <std::shared_ptr<GameObject>>&,std::shared_ptr<spaceShip>&);
	gameStatus runNewLevel(size_t levelNum);

private:

	// Data Members
	BackgroundManager m_background;
	sf::RenderWindow & m_window;
	std::vector<std::shared_ptr<GameObject>> &m_gameObjectVector;
	sf::Vector2u borders;
	std::shared_ptr<spaceShip> m_player;
	sf::Clock theGameClock;
	sf::Clock shootingClock;
	gameStatus _gameState;
	LevelUpdater _levelUpdater;
	size_t numberOfChickens;
	float deltaTime;
	std::stringstream _stream;


	// Helpers
	sf::Vector2f findAChickenPosition() const;
	void checkPlayerMove();
	void generateEggs(size_t);
	bool isNextDirectionValid(GameObject&, direction);
	bool collide(GameObject&, GameObject& );
	void moveDynamicObjects();
	void checkObjectsCollision();
	void draw(size_t);
	void pauseLevel();
	void handleEvent(sf::Event &);
	void checkForDyingObjects();
	bool checkForLevelState();
};
