/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include "LevelUpdater.h"

/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// Implementations /////////////////////////////////////

//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
LevelUpdater::LevelUpdater(sf::RenderWindow & window)
	:_window(window), _score("Score: "), _lives("Lives: "), _rect({ 200.f, 150.f }),
	_texts(ResourcesManager::instance().getScoreBoardTexts())
{
	_rect.setPosition(sf::VideoMode::getDesktopMode().width -203.f, 2.f);
	_rect.setFillColor(sf::Color::Transparent);
	_rect.setOutlineThickness(3.f);
	_rect.setOutlineColor(sf::Color(255,158,0,200));
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void LevelUpdater::update(int playerScore, int playerLives)
{
	_score = "Score: ";
	_lives = "Lives: ";
	_buffer << playerScore;
	_score += _buffer.str();
	_texts[0]->setString(_score);
	_buffer.str("");
	_buffer << playerLives;
	_lives += _buffer.str();
	_texts[1]->setString(_lives);
	_buffer.str("");
}
//-------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------//
void LevelUpdater::draw()
{
	_window.draw(_rect);
	_window.draw(*_texts[0]);
	_window.draw(*_texts[1]);
}
//-------------------------------------------------------------------------------------//