#include "NameIdentifier.h"


NameIdentifier::NameIdentifier(std::string val) : value(val) {}

NameIdentifier::~NameIdentifier()
{
}


std::vector<std::string> NameIdentifier::evaluate(VariablesMap& map)
{
	std::vector<std::string> temp;
	temp.push_back(value);
	return temp;
}
