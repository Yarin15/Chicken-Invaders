#include "BackgroundManager.h"



BackgroundManager::BackgroundManager(sf::RenderWindow& wind) 
	: m_window(wind), frameSpeed(500.f), frameCounter(0.f), switchFrame(50.f)
{
	// Get the Background Sprites
	getBackgroundSprites();

	float bWidth = _gameBackground.first->getGlobalBounds().width;
	float bHight = _gameBackground.first->getGlobalBounds().height;

	_gameBackground.first->setScale(m_window.getSize().x / bWidth, m_window.getSize().y / bHight);
	_gameBackground.second->setScale(m_window.getSize().x / bWidth, m_window.getSize().y / bHight);
	_gameBackground.second->setPosition(0.f, -(float)m_window.getSize().y);
}

void BackgroundManager::getBackgroundSprites()
{
	auto & _res = ResourcesManager::instance();
	_gameBackground.first = std::make_unique <sf::Sprite>(*_res.getPicture("Background.jpg"));
	_gameBackground.second = std::make_unique <sf::Sprite>(*_res.getPicture("Background.jpg"));
}

void BackgroundManager::scrollBackground(sf::Clock & clock)
{
	m_window.draw(*_gameBackground.first);
	m_window.draw(*_gameBackground.second);

	frameCounter += frameSpeed * clock.restart().asSeconds();

	if (frameCounter >= switchFrame)
		return; 

	_gameBackground.first->move(0.f, 1.f);
	_gameBackground.second->move(0.f, 1.f);
	frameCounter = 0;

	if ((_gameBackground.first->getPosition().y) > m_window.getSize().y) //out of screen
		_gameBackground.first->setPosition(0.f, -(float)m_window.getSize().y);
	if ((_gameBackground.second->getPosition().y > m_window.getSize().y)) //out of screen
		_gameBackground.second->setPosition(0.f, -(float)m_window.getSize().y);

}