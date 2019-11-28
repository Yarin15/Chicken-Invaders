/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
#include <memory>
#include <string>
#include <map>
#include "GameObject.h"

typedef std::map<std::string, std::shared_ptr<GameObject>(*)()> mymap;
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is A DESIGN PATTERN OF FACTORY.
The class create the wanted object by a given name.
*/
/////////////////////////////////////////////////////////////////////////////////////////

class Factory {
public:
	static std::shared_ptr<GameObject> create(const std::string& name);
	static bool registerit(const std::string& name, std::shared_ptr<GameObject>(*)());

private:
	static mymap& getMap();
};