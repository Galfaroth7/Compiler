#pragma once
#include "Statement.h"
#include "Expression.h"
#include "VariablesMap.h"

class Loop :
	public Statement
{
public:
	Loop(std::string it, std::unique_ptr<Expression> list, std::unique_ptr<Statement> bl);
	~Loop();

private:

	std::string iterator;
	std::unique_ptr<Expression> collection;
	std::unique_ptr<Statement> block;
	void execute(VariablesMap& map) override;
};

