/////////////////////////////////////// Headers /////////////////////////////////////////

#pragma once
class FallingObject;
#include <memory>
#include <string>
#include <vector>
#include <map>

typedef std::vector<std::pair<std::string, std::shared_ptr<FallingObject>(*)()>> myVector;
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Documentation //////////////////////////////////////
/*
This class is A DESIGN PATTERN OF FACTORY.
The class create A random Falling Object object.
*/
/////////////////////////////////////////////////////////////////////////////////////////

class RandomFactory {
public:
	static std::shared_ptr<FallingObject> create();
	static bool registerit(const std::string& name, std::shared_ptr<FallingObject>(*)());

private:
	static myVector& getVector();
};