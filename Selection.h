#pragma once
#include "Statement.h"
#include "BinaryExpression.h"
class Selection :
	public Statement
{
public:
	Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl)
		: condition(std::move(cond)), ifBlock(std::move(ifBl)), elseSpecified(false) {}

	Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl, std::unique_ptr<Statement> elseBl)
		: condition(std::move(cond)), ifBlock(std::move(ifBl)), elseBlock(std::move(elseBl)), elseSpecified(true) {}
	~Selection();

private:
	std::unique_ptr<Expression> condition;
	std::unique_ptr<Statement> ifBlock;
	std::unique_ptr<Statement> elseBlock;
	bool elseSpecified;
};

