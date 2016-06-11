#pragma once
#include "Statement.h"
#include "Expression.h"
#include "VariablesMap.h"
class FunctionCall :
	public Statement
{
public:
	FunctionCall(std::string fName, std::vector<std::unique_ptr<Expression>>& args)
		: functionName(std::move(fName)), arguments(std::move(args)) {}
	~FunctionCall();

	void execute(VariablesMap& map)
	{
		auto scopeMap = map.withoutVariables();
		auto calledFunction = scopeMap.getFunction(functionName);
		auto argsNames = calledFunction->getArgs(scopeMap);
		//std::cout << argsNames.size(); 
		/*
		if (argsNames.size() != arguments.size())
			throw std::runtime_error("Function " + functionName + " called with invalid number of arguments.");
		auto name = argsNames.begin();
		for (auto bind = arguments.begin(); name != argsNames.end(); ++name, ++bind) {
			scopeMap.storeVariable(*name, (*bind)->evaluate(map));
		}
		calledFunction->execute(scopeMap);*/
	}

private:
	std::string functionName;
	std::vector<std::unique_ptr<Expression>> arguments;

};

