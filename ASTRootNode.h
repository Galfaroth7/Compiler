#pragma once
#include <vector>

class ASTRootNode {
public:

	
	ASTRootNode(std::vector<int>& functions, std::vector<int>& statements) :
		functions(functions), statements(statements) { }

	void execute()
	{
		for (auto fun : functions)
		{
			auto name = fun.getName();
			map.storeFunction(name, fun);
		}
		for (const auto statement : statements)
			statement.execute(map);
		return;
	}

private:

	std::vector<int> functions;
	std::vector<int> statements;
	VariablesMap map;
};