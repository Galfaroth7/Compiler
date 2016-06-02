#pragma once
#include "Expression.h"
class BinaryExpression : public Expression
{
public:
	BinaryExpression(std::unique_ptr<Expression> left, BinaryOperator op, std::unique_ptr<Expression> right)
		: leftOperand(std::move(left)), op(op), rightOperand(std::move(right)) {}
	
	//std::unique_ptr<Expression> evaluate(const VariablesMap&) override;

private:
	std::unique_ptr<Expression> leftOperand;
	std::unique_ptr<Expression> rightOperand;
	BinaryOperator op;
};

