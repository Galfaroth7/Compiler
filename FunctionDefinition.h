#pragma once
#include "Statement.h"
#include "Expression.h"
#include "NameIdentifier.h"

class FunctionDefinition :
	public Statement
{
public:
	FunctionDefinition(std::unique_ptr<Expression> fName, std::vector<std::unique_ptr<Expression>>& args, std::unique_ptr<Statement> fbody)
		: functionName(std::move(fName)), arguments(std::move(args)), body(std::move(fbody))   {}
	
	~FunctionDefinition();


private:
	std::unique_ptr<Expression> functionName;
	std::vector<std::unique_ptr<Expression>> arguments;
	std::unique_ptr<Statement> body;

};

