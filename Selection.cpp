#include "Selection.h"


Selection::Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl)
	: condition(std::move(cond)), ifBlock(std::move(ifBl)), elseSpecified(false) {}

Selection::Selection(std::unique_ptr<Expression> cond, std::unique_ptr<Statement>ifBl, std::unique_ptr<Statement> elseBl)
	: condition(std::move(cond)), ifBlock(std::move(ifBl)), elseBlock(std::move(elseBl)), elseSpecified(true) {}

Selection::~Selection()
{
}

void Selection::execute(VariablesMap& map)
{
	auto result = condition->evaluate(map);
	if (*result.begin() == "TRUE")
		ifBlock->execute(map);
	else if (elseSpecified)
		elseBlock->execute(map);
}
