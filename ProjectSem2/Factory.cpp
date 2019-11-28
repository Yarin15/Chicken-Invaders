#include "Factory.h"
#include "UnknownObject.h"

//-------------------------------------------------------------------------------------//
// The follwoing function is the factory create function.
// The function gets a string and returns a function that creates a new object.
// If a string of an object which isn't registered is asked "UnknownObject is thrown".
//-------------------------------------------------------------------------------------//
std::shared_ptr<GameObject> Factory::create(const std::string& name)
{
	auto it = getMap().find(name);
	if (it == getMap().end()) {
		std::string _error(name);
		_error += "is unknown type of object. Object isn't registered";
		throw UnknownObject(_error);
	}
	return it->second();
}
//-------------------------------------------------------------------------------------//
// This if the registering function for the factory.
// It gets a string and pointer to a function, the function will emplace the wanted
// 
//-------------------------------------------------------------------------------------//
bool Factory::registerit(const std::string& name, std::shared_ptr<GameObject>(*f)()) {
	getMap().emplace(name, f);
	return true;
}
//-------------------------------------------------------------------------------------//
// This private function returns the map of the objects
//-------------------------------------------------------------------------------------//
mymap& Factory::getMap()
{
	static mymap m_map;
	return m_map;
}
