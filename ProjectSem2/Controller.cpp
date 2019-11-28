#include "Controller.h"
#include "Wave1.h"
#include "WaveBoss1.h"
#include "WaveBoss2.h"
#include "WaveBoss3.h"
#include "Wave2.h"
#include "Wave3.h"
#include "Wave4.h"
#include "Wave5.h"
//---------------------------------------------------------------------------//
//-------------------------------C-Tor---------------------------------------//
//---------------------------------------------------------------------------//
Controller::Controller()
	:_res(ResourcesManager::instance()),
	m_window(sf::VideoMode(600, 600), "Chicken Invaders", sf::Style::Fullscreen),
	levelNum(0),
	m_player(std::static_pointer_cast<spaceShip>(Factory::create("spaceShip"))),
	m_level(m_window, m_gameObjectVector, m_player), m_menu(m_window, GAME_MENU_T)
{
	sf::Vector2u windowBorders = m_window.getSize();
	m_window.setFramerateLimit(60);
}
//---------------------------------------------------------------------------//
//The following function starts the game and runs the menu and excute the waves
//---------------------------------------------------------------------------//
void Controller::playGame()
{
	while (m_window.isOpen())
	{
		m_menu.run();
		runLevel();
	}
}
//---------------------------------------------------------------------------//
//The following function manage the levels that appear to be in the waveVector
//it take each wave (level) and go to the level manager that runs the wave
//---------------------------------------------------------------------------//
void Controller::runLevel()
{
	m_player->restart();
	unsigned waveNumber = 0;
	fillWavesVector();

	do {
		m_gameObjectVector.emplace_back(m_player);
		m_window.clear();
		moveBetweenWaves(waveNumber + 1);
		m_waves[waveNumber]->createWave();
		m_waves[waveNumber]->getWaveStage(m_gameObjectVector);
		m_status = m_level.runNewLevel(waveNumber);
		waveNumber++;
		m_gameObjectVector.resize(0);
	} while (m_status == CONTINUE_T && waveNumber != m_waves.size());

	m_status == GAME_OVER_T ? gameEnded("     GAME OVER your final score", "gameOver.ogg") :
							  gameEnded(" You WON the game\n   your final score", "claps.ogg");

	m_gameObjectVector.resize(0);
}
//---------------------------------------------------------------------------//
//The following function fill the waves vector with the wishes stages
//---------------------------------------------------------------------------//
void Controller::fillWavesVector()
{
	m_waves.resize(0);

	m_waves.emplace_back(std::make_unique <Wave1>());
	m_waves.emplace_back(std::make_unique <Wave2>());
	m_waves.emplace_back(std::make_unique <Wave3>());
	m_waves.emplace_back(std::make_unique <Wave4>());
	//m_waves.emplace_back(std::make_unique <WaveBoss1>());
	m_waves.emplace_back(std::make_unique <WaveBoss3>());
	m_waves.emplace_back(std::make_unique <WaveBoss2>());
}
//---------------------------------------------------------------------------//
// The follwing function stops and advance notice about forwarding next Level
//---------------------------------------------------------------------------//
void Controller::moveBetweenWaves(size_t waveNumber)
{
	_wavesMovement.restart();
	sf::Text text("", ResourcesManager::instance().getFont(), 120);
	text.setFillColor(sf::Color::Transparent);
	text.setOutlineColor(sf::Color::Yellow);
	text.setOutlineThickness(2);
	text.setPosition({ 400.f, 350.f });

	while (_wavesMovement.getElapsedTime().asSeconds() < 5)
	{
		_stream << "         Get Ready!\nWave number " << waveNumber << " starts in: \n" <<
			"                 " << 5 - (int)_wavesMovement.getElapsedTime().asSeconds();
		text.setString(_stream.str());
		m_window.draw(text);
		m_window.display();
		m_window.clear();
		_stream.str("");              // Initialize the _Stream
	}
}
//---------------------------------------------------------------------------//
void Controller::gameEnded(std::string toPrint, std::string sound)
{
	SoundManager::instance().playSound(sound);
	sf::Text text("", ResourcesManager::instance().getFont(), 120);
	toPrint += ":\n                     ";
	_stream << toPrint << m_player->getScore();
	text.setString(_stream.str());
	text.setPosition({ 250.f, 350.f });
	text.setFillColor(sf::Color::Transparent);
	text.setOutlineColor(sf::Color::Magenta);
	text.setOutlineThickness(2);
	_wavesMovement.restart();
	while (_wavesMovement.getElapsedTime().asSeconds() < 5)
	{
		m_window.clear();
		m_window.draw(text);
		m_window.display();
	}

}