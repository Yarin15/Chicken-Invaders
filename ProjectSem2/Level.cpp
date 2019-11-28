#include "Level.h"
#include "PauseMenu.h"
#include "LevelUpdater.h"
#include "UnknownCollision.h"

//---------------------------------------------------------------------------//
//-------------------------------C-Tor---------------------------------------//
//---------------------------------------------------------------------------//
Level::Level(sf::RenderWindow& wind, std::vector <std::shared_ptr<GameObject>>&
			 m_objects, std::shared_ptr<spaceShip>& player)
	:m_window(wind), m_player(player), m_background(wind),
	borders(m_window.getSize().x, m_window.getSize().y - 100),
	m_gameObjectVector(m_objects), _levelUpdater(wind)
{
	m_player->setPosition({(float)borders.x / 2, (float)borders.y - 150.f });
}
//---------------------------------------------------------------------------//
// STL-like algorithm to run over all pairs
//---------------------------------------------------------------------------//
template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (FwdIt second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}
//---------------------------------------------------------------------------//
//The following function checks if there is collision happend between SHIP
//BULLETS/ PRIZES / CHICKENS
//---------------------------------------------------------------------------//
void Level::checkObjectsCollision()
{
	for_each_pair(m_gameObjectVector.begin(), 
		m_gameObjectVector.end(), [this](auto& a, auto& b) {
		if (collide(*a, *b))
		{
			processCollision(*a, *b);
		}
	});
	
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
bool Level::collide(GameObject& obj1, GameObject& obj2)
{
	auto obj1GlobalBounds = obj1.getGlobalBounds();
	obj1GlobalBounds.left += 4.f;
	obj1GlobalBounds.top += 4.f;
	obj1GlobalBounds.width -= 8.f;
	obj1GlobalBounds.height -= 8.f;
	return (obj1GlobalBounds.intersects(obj2.getGlobalBounds()));
}
//---------------------------------------------------------------------------//
//The following function get the number of level and runs the level until it
//finish means- no Chockens on board or user run out of lives.
//The function call to all other function to fulfill it mission
//---------------------------------------------------------------------------//
gameStatus Level::runNewLevel(size_t waveNum)
{
	// Event to be taken care of
	sf::Event Event;
	numberOfChickens = m_gameObjectVector.size() - 1;

	while (m_window.isOpen() && checkForLevelState())
	{
		try {
			if (m_window.pollEvent(Event))
				handleEvent(Event);

			// Restart the clock for the next Iteration
			moveDynamicObjects();
			generateEggs(waveNum);
			checkObjectsCollision();
			checkForDyingObjects();
			_levelUpdater.update(m_player->getScore(), m_player->getLives());
			m_player->checkAndIncreaseLives();

			// Draw Level Objects
			m_window.clear();
			m_background.scrollBackground(theGameClock);
			draw(waveNum);
			m_window.display();
		}
		catch (std::out_of_range & e)
		{
			std::string message = __func__;
			message += "line: ";
			_stream << __LINE__;
			message += _stream.str();
			message += e.what();
			Logger::instance().Write(message);
			_stream.str("");
		}
		catch (UnknownCollision & e)
		{
			std::string message = __func__;
			message += "line: ";
			_stream << __LINE__;
			message += _stream.str();
			message += e.what();
			Logger::instance().Write(message);
			_stream.str("");
		}
		catch (const std::exception & e)
		{
			std::string message = __func__;
			message += "line: ";
			_stream << __LINE__;
			message += _stream.str();
			message += e.what();
			Logger::instance().Write(message);
			_stream.str("");
		}

	}
	return _gameState;
}

//---------------------------------------------------------------------------//
//The following function moves the dynamic objects of the current level on the
//grid (SHIP, CHICKENS, BONES, BULLETS)
//---------------------------------------------------------------------------//
void Level::checkPlayerMove()
{
	float deltaTime = theGameClock.restart().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(isNextDirectionValid(*m_player, UP_T))
			m_player->moveObj(deltaTime, UP_T);
	}		
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (isNextDirectionValid(*m_player, DOWN_T))
			m_player->moveObj(deltaTime, DOWN_T);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (isNextDirectionValid(*m_player, LEFT_T))
			m_player->moveObj(deltaTime, LEFT_T);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (isNextDirectionValid(*m_player, RIGHT_T))
			m_player->moveObj(deltaTime, RIGHT_T);
	}
	
}
//-------------------------------------------------------------------------------------//
// The function generates eggs on the screen. The ammount and the frequancy is dependent
// on the wave num.
//-------------------------------------------------------------------------------------//
void Level::generateEggs(size_t waveNumber)
{
	static float lastTimeShot = 0.f;

	if (shootingClock.getElapsedTime().asSeconds() - lastTimeShot > 4.5f - waveNumber*0.85) {
		std::shared_ptr<Egg> newEgg = std::static_pointer_cast<Egg>(Factory::create("Egg"));
		auto _pos = findAChickenPosition();
		newEgg->setPosition({ _pos.x + CHIC_SPR_X / 2, _pos.y + CHIC_SPR_Y / 2 });
		m_gameObjectVector.emplace_back(newEgg);
		lastTimeShot = shootingClock.getElapsedTime().asSeconds();
	}
}
//-------------------------------------------------------------------------------------//
// This function raffles an index at the vector size range.
// While a chicken hasn't been found, it'll keep looking for a chicken.
// When found, the function will return the chicken position.
//-------------------------------------------------------------------------------------//
sf::Vector2f Level::findAChickenPosition() const
{
	size_t index;

	index = (rand() % numberOfChickens) + 1;
	if (index < 0 && index >= m_gameObjectVector.size())
		throw std::out_of_range("Index is outr of the vector range");
	return m_gameObjectVector[index]->getPosition();
}
//-------------------------------------------------------------------------------------//
// This function checks whether the next move of the player is valid
//-------------------------------------------------------------------------------------//
bool Level::isNextDirectionValid(GameObject & obj, direction dir)
{
	switch (dir)
	{
		case UP_T:
		return (m_player->getGlobalBounds().top >= 0);
		case DOWN_T:
		return (m_player->getGlobalBounds().top + m_player->getGlobalBounds().height < borders.y);
		case LEFT_T:
		return (m_player->getGlobalBounds().left >= 0);
		case RIGHT_T:
		return (m_player->getGlobalBounds().left + m_player->getGlobalBounds().width < borders.x);

		default:
		return false;
	}
}
//-------------------------------------------------------------------------------------//
//The following function moves the dynamic objects of the current level on the
//grid (SHIP, CHICKENS, BONES, BULLETS)
//-------------------------------------------------------------------------------------//
void Level::moveDynamicObjects()
{
	checkPlayerMove();
	float deltaTime = theGameClock.restart().asSeconds();
	for (auto & object : m_gameObjectVector)
		object->moveObj(deltaTime, NONE_T);
}
//-------------------------------------------------------------------------------------//
//The following function gets the window and draw on it the static and dynamic
//objects of the level
//-------------------------------------------------------------------------------------//
void Level::draw(size_t levelNum)
{
	for (auto & object : m_gameObjectVector)
		object->draw(m_window);

	_levelUpdater.draw();
}
//-------------------------------------------------------------------------------------//
// This function is called when an ESCPASE was pressed and the user. The function
// will generate and open a new render window with a pause menu.
//-------------------------------------------------------------------------------------//
void Level::pauseLevel()
{
	sf::RenderWindow pauseWindow(sf::VideoMode(400, 300), "Pause", sf::Style::Titlebar);
	PauseMenu pause(pauseWindow, m_window);
	pause.run();
}
//-------------------------------------------------------------------------------------//
// This function is called when an event is waiting on the pollEvent queue.
// The function will handle the events given by the operating system.
//-------------------------------------------------------------------------------------//
void Level::handleEvent(sf::Event & Event)
{
	static float lastTimeShot = 0.f;
	switch (Event.type)
	{
	case sf::Event::KeyPressed:
		switch (Event.key.code)
		{
		case sf::Keyboard::Escape:
			pauseLevel();
			break;
		case sf::Keyboard::Space:
		if (shootingClock.getElapsedTime().asSeconds() - lastTimeShot> 0.3f) {
			m_player->makeAttack(m_gameObjectVector);
			lastTimeShot = shootingClock.getElapsedTime().asSeconds();
		}
			break;
		}
	}

}
//-------------------------------------------------------------------------------------//
// This function checks if the bullets are out of bounds.
// The function will erase the ones whom OUB;
//-------------------------------------------------------------------------------------//
void Level::checkForDyingObjects()
{
	for (size_t i = 0; i < m_gameObjectVector.size(); i++) {
		if (m_gameObjectVector[i]->getLive() <= 0)
		{
			if (typeid(*(m_gameObjectVector[i])) == typeid(Chicken))
			{
				numberOfChickens--;
				auto chicken = std::static_pointer_cast<Chicken>(m_gameObjectVector[i]);
				m_gameObjectVector.emplace_back(chicken->getDroppedObject());
				m_player->setScore(SCORE_CHICKEN_KILL);
			}

			m_gameObjectVector.erase(m_gameObjectVector.begin() + i);
			i--;
		}
	}
}
//-------------------------------------------------------------------------------------//
//The following function checks for the level state - means it finds out if
//the ship still alive and if there is any chickens in the wave and follow the
//next stage or going back to the menu
//-------------------------------------------------------------------------------------//
bool Level::checkForLevelState()
{
	if (typeid(*m_gameObjectVector[0]) != typeid(spaceShip)) {
		_gameState = GAME_OVER_T;
		// Get out
		return false;
	}

	if (std::any_of(m_gameObjectVector.begin(), m_gameObjectVector.end(),
		[](const auto & object)
	{return (typeid(*object) == typeid(Chicken)|| typeid(*object) == typeid(ChickenBoss1)
		|| typeid(*object) == typeid(ChickenBoss2) || typeid(*object) == typeid(ChickenBoss3)); })) {
		// Keep playing the level
		return true;
	}

	//continue to next level
	_gameState = CONTINUE_T;
	return false;
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//