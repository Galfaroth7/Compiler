#pragma once
#include "Expression.h"
#include "Statement.h"
#include <iostream>

class ASTRootNode {
public:


	ASTRootNode(std::vector<std::unique_ptr<Statement>>& functions,std::vector<std::unique_ptr<Statement>>& assignments, std::vector<std::unique_ptr<Statement>>& statements) :
		functions(std::move(functions)), assignments(std::move(assignments)), statements(std::move(statements)) { }

	void execute()
	{
		for (auto& assign : assignments)
		{
			assign->execute(map);
		}
		
		for (const auto& statement : statements)
			statement->execute(map);
		
		return;
	}

private:

	std::vector<std::unique_ptr<Statement>> functions;
	std::vector<std::unique_ptr<Statement>> statements;
	std::vector<std::unique_ptr<Statement>> assignments;
	
	VariablesMap map;
};