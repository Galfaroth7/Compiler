#pragma once
#include "Statement.h"
#include "Expression.h"
#include "VariablesMap.h"
#include <iostream>

class BuildStatement : public Statement
{
public:
	BuildStatement(std::unique_ptr<Expression> target, std::unique_ptr<Expression> dependencies, std::unique_ptr<Expression> buildCommand);
	~BuildStatement() {}
	bool getBuilt(){ return isBuilt; }

	
	
private:
	std::unique_ptr<Expression> target;
	std::unique_ptr<Expression> dependencies;
	std::unique_ptr<Expression> buildCommand;
	bool isBuilt;

	std::string getTarget(VariablesMap& map)
	{
		auto targetResult = target->evaluate(map);
		if (targetResult.size() != 1)
		{
			//throw error
		}
		return *targetResult.begin();
	}


	void execute(VariablesMap& map) override;

};

