#pragma once
#include "Expression.h"
#include "VariablesMap.h"

class VariableIdentifier :
	public Expression
{
public:
	
	VariableIdentifier(std::string val);
	~VariableIdentifier();
	
	
private:
	std::string value;
	std::vector<std::string> evaluate(VariablesMap& map) override;
};

