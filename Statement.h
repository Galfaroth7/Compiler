#pragma once

#include <memory>

class VariablesMap;

class Statement {
public:
	

	virtual ~Statement() {}
	
	virtual void execute(VariablesMap& map) = 0;
};