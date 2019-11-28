#include "Logger.h"


//---------------------------------------------------------------------------//
// Logger constructor. Opens the file to the logger
//---------------------------------------------------------------------------//
Logger::Logger()
{
	_log.open("Logger.txt");
	if (!_log.is_open())
		throw std::ios_base::failure("Couldn't Open Logger File!");
}
//---------------------------------------------------------------------------//
// The singeltone function to return the instace of the singeltone.
//---------------------------------------------------------------------------//
Logger & Logger::instance()
{
	static Logger _instance;
	return _instance;
}
//---------------------------------------------------------------------------//
// The function gets a message. 
//---------------------------------------------------------------------------//
void Logger::Write(std::string& _message)
{
	_log << _message << "\n";
}
//---------------------------------------------------------------------------//
// Logger D-tor closes the ofstream file.
//---------------------------------------------------------------------------//
Logger::~Logger()
{
	_log.close();
}
