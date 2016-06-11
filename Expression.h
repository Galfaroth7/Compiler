#pragma once
#include <memory>
#include <string>
#include <vector>

class VariablesMap;

class Expression
{
public:
	Expression() {}
	virtual ~Expression() {}


	enum class BinaryOperator
	{
		AND,
		OR,
		EQUAL,
	};


	virtual std::vector<std::string> evaluate(VariablesMap& map ) = 0;
};

