#pragma once
#include "Statement.h"
#include "Expression.h"

class BuildStatement : public Statement
{
public:
	BuildStatement(std::unique_ptr<Expression> target, std::unique_ptr<Expression> dependencies, std::unique_ptr<Expression> buildCommand)
		: target(std::move(target)), dependencies(std::move(dependencies)), buildCommand(std::move(buildCommand)) {}
	
	~BuildStatement();
	//void execute();
private:
	std::unique_ptr<Expression> target;
	std::unique_ptr<Expression> dependencies;
	std::unique_ptr<Expression> buildCommand;
	
	

};

