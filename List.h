#pragma once
#include "Expression.h"
#include <vector>

class List :
	public Expression
{
public:
	List(std::vector<std::unique_ptr<Expression>> elems) : elements(std::move(elems)) {}
	~List();

private:
	std::vector<std::unique_ptr<Expression>> elements;

};

