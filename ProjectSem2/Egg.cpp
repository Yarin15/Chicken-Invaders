#include "Egg.h"

Egg::Egg()
{
	Img = std::move(ResourcesManager::instance().getPicture("egg.png"));
	dyingFlag = true;
}
//-------------------------------------------------------------------------------------//
// This function sets the egg image to the splat egg image.
// The function will be called when an egg stopps at the ground
//-------------------------------------------------------------------------------------//
void Egg::setSplatImage()
{
	Img = std::move(ResourcesManager::instance().getPicture("eggSplat.png"));
}
//-------------------------------------------------------------------------------------//
// This function overrides FallingObject::moveObj
//-------------------------------------------------------------------------------------//
void Egg::moveObj(float, direction)
{
	if (Img->getPosition().y < windowSize.y - 50.f)
		Img->move(0.f, (float) (rand() % 3) + 6);
	else
	{
		if (dyingFlag) {
			time = deadTimer.restart().asSeconds();
			sf::Vector2f _pos = Img->getPosition();
			dyingFlag = false;
			setSplatImage();
			Img->setPosition(_pos.x - 20.f, _pos.y);
			SoundManager::instance().playSound("EggDestroied.ogg");
		}
		if (deadTimer.getElapsedTime().asSeconds() > 3.f)
			m_lives = 0;
	}
}

