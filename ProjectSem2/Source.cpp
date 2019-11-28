
/////////////////////////////////// Headers ///////////////////////////////////



#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <iostream>
#include <cstdlib>
#include "Controller.h" 

//////////////////////////////////////////////////////////////////////

int main()
{
	Controller controller;

	controller.playGame();
	return EXIT_SUCCESS;
}

