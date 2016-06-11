#pragma once
#include "Statement.h"
#include "BinaryExpression.h"
class Selection :
	public Statement
{
public:
	Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl);
	Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl, std::unique_ptr<Statement> elseBl);
	~Selection();

	
private:
	std::unique_ptr<Expression> condition;
	std::unique_ptr<Statement> ifBlock;
	std::unique_ptr<Statement> elseBlock;
	void execute(VariablesMap& map) override;
	bool elseSpecified;
};

