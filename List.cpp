#include "List.h"


List::List(std::vector<std::unique_ptr<Expression>> elems) : elements(std::move(elems)) {}

List::~List()
{
}


std::vector<std::string> List::evaluate(VariablesMap& map)
{
	std::vector<std::string> newVector;
	for (auto& elem : elements)
	{
		for (auto& str : elem->evaluate(map))
			newVector.push_back(str);
	}
	return newVector;
}
