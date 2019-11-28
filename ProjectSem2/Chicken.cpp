#pragma once
#include "Chicken.h"
#include "ResourcesManager.h"

//---------------------------------------------------------------------------//
// Chicken Object Constructor
//---------------------------------------------------------------------------//
Chicken::Chicken()
	:_sheetPos(1,0), frameSpeed(500.f), frameCounter(0.f), switchFrame(100.f)
{
	m_lives = 1;
	auto & _res = ResourcesManager::instance();
	Img = std::move(_res.getPicture("chicken.png"));
	_dropObject = RandomFactory::create();
}
//---------------------------------------------------------------------------//
// Overriding GameObject draw function
// The object has a sprite sheet and needs to be cut.
//---------------------------------------------------------------------------//
void Chicken::draw(sf::RenderWindow & _window)
{
	frameCounter += frameSpeed * _spriteSheetClock.restart().asSeconds();
	if (frameCounter >= switchFrame){
		// Move to the next sprite on sheet.
		_sheetPos.x++;
		if (_sheetPos.x * CHIC_SPR_Y >= CHICKEN_SRPITE)
			  _sheetPos.x = 0;
		frameCounter = 0;
	}

	Img->setTextureRect(sf::IntRect(_sheetPos.x * CHIC_SPR_Y, 0, CHIC_SPR_Y, CHIC_SPR_X));
	_window.draw(*Img);
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
std::shared_ptr<GameObject> Chicken::getDroppedObject() const
{		
	_dropObject->setPosition({ Img->getPosition().x + CHIC_SPR_X / 2,
		Img->getPosition().y + CHIC_SPR_Y / 2 });
	return _dropObject;
}


