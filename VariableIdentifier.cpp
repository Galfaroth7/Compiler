#include "VariableIdentifier.h"


VariableIdentifier::VariableIdentifier(std::string val) : value(val) {}

VariableIdentifier::~VariableIdentifier()
{
}


std::vector<std::string> VariableIdentifier::evaluate(VariablesMap& map)
{
	return map.getVariable(value);
}