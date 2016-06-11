#pragma once

#include <vector>
#include <memory>
#include "Statement.h"

class Block : public Statement {
public:

	Block() {};

	
	Block(std::vector<std::unique_ptr<Statement>>& statements) :
		statements(std::move(statements)) { }


	void execute(VariablesMap& map) override
	{
		for (auto& statement : statements)
			statement->execute(map);
	}

private:

	std::vector<std::unique_ptr<Statement>> statements;
};