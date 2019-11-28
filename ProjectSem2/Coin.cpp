#include "Coin.h"

Coin::Coin()
	:_sheetPos(1, 0), _frameSpeed(500.f), _frameCounter(0.f), _switchFrame(50.f)
{
	Img = std::move(ResourcesManager::instance().getPicture("coin.png"));
}

//---------------------------------------------------------------------------//
// Overriding GameObject draw function
// The object has a sprite sheet and needs to be cut.
//---------------------------------------------------------------------------//
void Coin::draw(sf::RenderWindow & _window)
{
	_frameCounter += _frameSpeed * _spriteSheetClock.restart().asSeconds();
	if (_frameCounter >= _switchFrame) {
		// Move to the next sprite on sheet.
		_sheetPos.x++;
		if (_sheetPos.x * COIN_SPR_Y >= COIN_SPRITE)
			_sheetPos.x = 0;
		_frameCounter = 0;
	}

	Img->setTextureRect(sf::IntRect(_sheetPos.x * COIN_SPR_Y, 0, COIN_SPR_Y, COIN_SPR_X));
	_window.draw(*Img);
}
