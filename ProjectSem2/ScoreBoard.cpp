/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "ScoreBoard.h"
#include <iostream>
#include "ResourcesManager.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////

//-------------------------------------------------------------------------------------//
// The class c-tor. Gets the window to be drawn on and open the score file
//-------------------------------------------------------------------------------------//
ScoreBoard::ScoreBoard(sf::RenderWindow & window)
	:_m_window(window), _res(ResourcesManager::instance())
{
	// The high scores file
	openTheFile();
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
ScoreBoard::~ScoreBoard()
{
	_m_reader.close();
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void ScoreBoard::openTheFile()
{
	_m_reader.open("Resources/Scores.txt");
	if (!_m_reader.is_open())
		std::cerr << "Cannot Open File" << std::endl;
}
//-------------------------------------------------------------------------------------//
// This function deletes all the data at the scores file by delting it and creating 
// it again.
//-------------------------------------------------------------------------------------//
void ScoreBoard::deleteDataOnFile()
{
	_m_reader.close();
	remove("Resources/Scores.txt");
	openTheFile();
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void ScoreBoard::readScores()
{
	score_data d;          // The elemnt to be insert to the vector
	std::string data;      // The data to be read from the file

	// Emplace the heads.
	_scores_texts.emplace_back(std::make_unique <sf::Text>("Name:", _res.getFont(), 200),
							  std::make_unique <sf::Text>("Score:", _res.getFont(), 200));

	while (!_m_reader.eof()) {
		// Read the name
		_m_reader >> data;
		d.first = std::make_unique<sf::Text>(data, _res.getFont(), 200);
		_m_reader >> data;
		d.second = std::make_unique<sf::Text>(data, _res.getFont(), 200);
		_scores_texts.emplace_back(score_data(std::move(d.first), std::move(d.second)));
	}
	// Get back the start of the file
	_m_reader.seekg(std::ios::beg);
}

//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void ScoreBoard::execute()
{
	_m_window.draw(*_res.getPicture("ScoresList"));
	for (size_t i = 0; i < _scores_texts.size(); i++)
	{
		_scores_texts[i].first->setPosition({ 300.f, i*150.f + 20.f });
		_scores_texts[i].second->setPosition({ 700.f, i*150.f + 20.f });
		_m_window.draw(*_scores_texts[i].first);
		_m_window.draw(*_scores_texts[i].second);
	}

	_m_window.display();

	sf::Event Event;
	while (_m_window.waitEvent(Event))
		if (Event.type == sf::Event::KeyPressed)
			break;

	_m_window.clear();
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//