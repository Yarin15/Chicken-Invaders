#include "UnknownCollision.h"


//-------------------------------------------------------------------------------------//
// Unknown Collision C-tor
//-------------------------------------------------------------------------------------//
UnknownCollision::UnknownCollision(std::string errorMsg)
	: BaseException(errorMsg)
{
}
//-------------------------------------------------------------------------------------//
// Implementing what function.
//-------------------------------------------------------------------------------------//
const char* UnknownCollision::what() const 
{
	return m_errorMsg.c_str();
}