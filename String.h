#pragma once
#include "Expression.h"
#include <vector>
class String :
	public Expression
{
public:
	String(std::vector<std::unique_ptr<Expression>> elems) : elements(std::move(elems)) {}
	~String();

private:
	std::vector<std::unique_ptr<Expression>> elements;
};

