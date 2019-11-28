#include "GameObject.h"

GameObject::GameObject()
{
		windowSize.y = sf::VideoMode::getDesktopMode().height;
		windowSize.x = sf::VideoMode::getDesktopMode().width;	
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
void GameObject::draw(sf::RenderWindow& wind)
{
	wind.draw(*Img);
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
bool GameObject::isInBorder()
{
	sf::Vector2f pos = Img->getPosition();
	return (!(pos.x >= windowSize.x || pos.x < 0 || pos.y >= windowSize.y || pos.y < 0));
}
sf::Vector2u GameObject::getBorderSize() const
{
	return windowSize;
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
sf::FloatRect GameObject::getGlobalBounds() const
{
	return Img->getGlobalBounds();
}
void GameObject::setRotation(float rotateAngle)
{
	Img->setRotation(rotateAngle);
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
sf::Vector2f GameObject::getPosition() const 
{ 
	return Img->getPosition(); 
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
void GameObject::setPosition(sf::Vector2f pos)
{
	Img->setPosition(pos);
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
int GameObject::getLive() const 
{ 
	return m_lives; 
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//
void GameObject::decreaseLives()
{ 
	m_lives--;
}
//---------------------------------------------------------------------------//
//---------------------------------------------------------------------------//