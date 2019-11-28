#include "Resume.h"



Resume::Resume(sf::RenderWindow & window)
	:window(window)
{
}

void Resume::execute()
{
	window.close();
}