#pragma once
#include "Expression.h"
class VariableIdentifier :
	public Expression
{
public:
	
	VariableIdentifier(std::string val) : value(val) {}

	~VariableIdentifier();
	
	std::string variable() const override {
		return value;
	}

	virtual Type getType() const override {
		return Type::IDENTIFIER;
	}

private:
	std::string value;
};

