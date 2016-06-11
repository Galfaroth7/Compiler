#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(std::string fName, std::vector<std::unique_ptr<Expression>>& args, std::unique_ptr<Statement> fbody)
	: functionName(std::move(fName)), arguments(std::move(args)), body(std::move(fbody)) {}


FunctionDefinition::~FunctionDefinition()
{
}


std::string FunctionDefinition::getFunctionName()
{
	return functionName;
}

std::vector<std::string> FunctionDefinition::getArgs(VariablesMap& map)
{
	std::vector<std::string> evaluatedArgs;
	for (auto& elem : arguments)
	{
		for (auto& str : elem->evaluate(map))
			evaluatedArgs.push_back(str);
	}
	return evaluatedArgs;
}


void FunctionDefinition::execute(VariablesMap& map)
{
	body->execute(map);
}