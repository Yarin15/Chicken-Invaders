/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "MenuCommandInterface.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include "ResourcesManager.h"

/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////

/*
*/

/////////////////////////////////////////////////////////////////////////////////////////

// Typedef this pair.
typedef std::pair <std::unique_ptr<sf::Text>, std::unique_ptr<sf::Text>> score_data;

class ScoreBoard : public MenuCommandInterface {

public:
	ScoreBoard(sf::RenderWindow &);
	~ScoreBoard();
	virtual void execute();
	void readScores();
	void deleteDataOnFile();

private:
	std::ifstream _m_reader;
	sf::RenderWindow & _m_window;
	std::vector<score_data> _scores_texts;
	ResourcesManager & _res;

	void openTheFile();
};

