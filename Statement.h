#pragma once

#include <memory>

//class VariablesMap;

class Statement {
public:
	//typedef std::unique_ptr<Statement> SPtr;

	virtual ~Statement() {}
	//virtual void execute(VariablesMap& map) = 0;
};