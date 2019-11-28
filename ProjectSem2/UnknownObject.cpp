#include "UnknownObject.h"


//-------------------------------------------------------------------------------------//
// Unknown Object exception constructor
//-------------------------------------------------------------------------------------//
UnknownObject::UnknownObject(std::string errorMsg)
	: BaseException(errorMsg)
{
}
//-------------------------------------------------------------------------------------//
// Implementing the what function
//-------------------------------------------------------------------------------------//
const char * UnknownObject::what() const
{
	return m_errorMsg.c_str();
}
