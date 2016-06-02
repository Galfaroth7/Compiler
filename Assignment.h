#pragma once

#include <string>
#include "Statement.h"
#include "Expression.h"

class Assignment : public Statement {
public:

	Assignment(std::unique_ptr<Expression> variable, std::unique_ptr<Expression> assignable) :
		variable(std::move(variable)), assignable(std::move(assignable)) { };

	/*void execute(VariablesMap& map) override {
		map.storeVariable(varName_, assignable_->evaluate(map));
	}*/

private:

	std::unique_ptr<Expression> variable;
	std::unique_ptr<Expression> assignable;

};