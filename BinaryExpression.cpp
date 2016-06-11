#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(std::unique_ptr<Expression> left, BinaryOperator op, std::unique_ptr<Expression> right) :
	leftOperand(std::move(left)), rightOperand(std::move(right)), op(op) { }

BinaryExpression::~BinaryExpression()
{

}

std::vector<std::string> BinaryExpression::evaluate(VariablesMap& map)
{
	std::vector<std::string> newVector;

	bool result, leftBool, rightBool;
	auto leftEval = leftOperand->evaluate(map);
	auto rightEval = rightOperand->evaluate(map);
	if (leftEval.size() != 1 || rightEval.size() != 1)
	{
		//throw exception
	}
	switch (op)
	{
	case BinaryOperator::AND:
		leftBool = stringToBool(*leftEval.begin());
		rightBool = stringToBool(*rightEval.begin());
		result = (leftBool && rightBool);
		break;

	case BinaryOperator::OR:
		leftBool = stringToBool(*leftEval.begin());
		rightBool = stringToBool(*rightEval.begin());
		result = (leftBool || rightBool);
		break;

	case BinaryOperator::EQUAL:
		result = (*leftEval.begin() == *rightEval.begin());
		break;
	}

	if (result)
		newVector.push_back(std::string("TRUE"));
	else
		newVector.push_back(std::string("FALSE"));

	return newVector;
}

bool BinaryExpression::stringToBool(std::string evaluator)
{
	if (evaluator == std::string("TRUE"))
		return true;
	else
		return false;
}
