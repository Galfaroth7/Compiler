#pragma once
#include "Expression.h"
class BinaryExpression : public Expression
{
public:
	BinaryExpression(std::unique_ptr<Expression> left, BinaryOperator op, std::unique_ptr<Expression> right);
	~BinaryExpression();
	

private:
	std::unique_ptr<Expression> leftOperand;
	std::unique_ptr<Expression> rightOperand;
	BinaryOperator op;
	bool stringToBool(std::string);
	std::vector<std::string> evaluate(VariablesMap& map) override;

};

