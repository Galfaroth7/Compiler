#pragma once
#include "Statement.h"
#include "Expression.h"
#include "NameIdentifier.h"

class FunctionDefinition :
	public Statement
{
public:
	FunctionDefinition(std::string fName, std::vector<std::unique_ptr<Expression>>& args, std::unique_ptr<Statement> fbody);
	
	~FunctionDefinition();
	std::string getFunctionName();
	std::vector<std::string> getArgs(VariablesMap& map);
	void execute(VariablesMap& map);

private:
	std::string functionName;
	std::vector<std::unique_ptr<Expression>> arguments;
	std::unique_ptr<Statement> body;
	
};

