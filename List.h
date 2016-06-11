#pragma once
#include "Expression.h"
#include <vector>

class List :
	public Expression
{
public:
	List(std::vector<std::unique_ptr<Expression>> elems);
	~List();

private:
	std::vector<std::unique_ptr<Expression>> elements;
	std::vector<std::string> evaluate(VariablesMap& map) override;
	
};

