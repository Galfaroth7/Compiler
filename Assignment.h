#pragma once

#include <string>
#include "Statement.h"
#include "Expression.h"
#include "VariablesMap.h"

class Assignment : public Statement {
public:

	Assignment(std::string variable, std::unique_ptr<Expression> assignable) :
		variable(std::move(variable)), assignable(std::move(assignable)) { };

	void execute(VariablesMap& map) override
	{
		map.storeVariable(variable, assignable->evaluate(map));
	}

private:

	std::string variable;
	std::unique_ptr<Expression> assignable;

};