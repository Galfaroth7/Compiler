#include "String.h"


String::String(std::vector<std::unique_ptr<Expression>> elems) : elements(std::move(elems)) {}

String::~String()
{
}

std::vector<std::string> String::evaluate(VariablesMap& map)
{
	std::vector<std::string> newVector;
	for (auto& elem : elements)
	{
		for (auto& str : elem->evaluate(map))
			newVector.push_back(str);
	}
	return newVector;
}
