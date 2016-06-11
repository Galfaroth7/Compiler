#pragma once
#include "Expression.h"
#include <string>
#include <sstream>

class FileIdentifier :
	public Expression
{
public:
	FileIdentifier(std::unique_ptr<Expression> val, std::string& ext);
	~FileIdentifier();


private:
	std::unique_ptr<Expression> value;
	std::string extension;
	std::vector<std::string> evaluate(VariablesMap& map) override;


};

