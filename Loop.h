#pragma once
#include "Statement.h"
#include "Expression.h"
class Loop :
	public Statement
{
public:
	Loop(std::unique_ptr<Expression> it, std::unique_ptr<Expression> list, std::unique_ptr<Statement> bl) :
		iterator(std::move(it)), collection(std::move(list)), block(std::move(bl)) {}
	~Loop();

private:

	std::unique_ptr<Expression> iterator;
	std::unique_ptr<Expression> collection;
	std::unique_ptr<Statement> block;

};

