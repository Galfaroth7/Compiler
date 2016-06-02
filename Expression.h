#pragma once
#include <memory>
#include <string>
#include <vector>

class Expression
{
public:
	Expression() {}
	virtual ~Expression() {}


	enum class Type
	{
		IDENTIFIER,
		FILE,
		VARIABLE,
		LIST,
		STRING,
		FUN_CALL,
		NOT_SPECIFIED
	};

	enum class BinaryOperator
	{
		AND,
		OR,
		EQUAL,
	};


	virtual std::string variable() const {
		throw std::runtime_error("Not overriden variable method.");
	}

	virtual Type getType() const {
		return Type::NOT_SPECIFIED;
	}

	//virtual std::unique_ptr<Expression> 

	//virtual std::unique_ptr<Expression> evaluate() = 0;
};

