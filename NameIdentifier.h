#pragma once
#include "Expression.h"
class NameIdentifier :
	public Expression
{
public:
	NameIdentifier(std::string val) : value(val) {}
	
	~NameIdentifier();
	std::string variable() const override {
		return value;
	}

	virtual Type getType() const override {
		return Type::IDENTIFIER;
	}

private:
	std::string value;

};

