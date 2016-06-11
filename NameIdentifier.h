#pragma once
#include "Expression.h"
class NameIdentifier :
	public Expression
{
public:
	NameIdentifier(std::string val);	
	~NameIdentifier();
	
private:
	std::string value;
	std::vector<std::string> evaluate(VariablesMap& map) override;

};

