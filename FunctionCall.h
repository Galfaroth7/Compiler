#pragma once
#include "Statement.h"
#include "Expression.h"
class FunctionCall :
	public Statement
{
public:
	FunctionCall(std::unique_ptr<Expression> fName, std::vector<std::unique_ptr<Expression>>& args)
		: functionName(std::move(fName)), arguments(std::move(args)) {}
	~FunctionCall();

private:
	std::unique_ptr<Expression> functionName;
	std::vector<std::unique_ptr<Expression>> arguments;

};

