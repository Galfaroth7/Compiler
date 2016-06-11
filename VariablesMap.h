#pragma once
#include <unordered_map>
#include "FunctionDefinition.h"

class BuildStatement;

class VariablesMap {

public:

	bool containsVariable(const std::string& varname) const;
	void storeVariable(const std::string& varname, const std::vector<std::string> value);
	void eraseVariable(const std::string& varname);
	void storeBuildStatement(const std::string& key, std::shared_ptr<BuildStatement>& build);
	std::vector<std::string> getVariable(const std::string& key) const;
	std::shared_ptr<BuildStatement> getBuildStatement(const std::string& key);
	bool buildExists(const std::string& key);
	void storeFunction(const std::string& funName, const std::shared_ptr<FunctionDefinition>& value);
	std::shared_ptr<FunctionDefinition> getFunction(const std::string& key) const;
	std::unique_ptr<Expression> getCallResult();
	VariablesMap withoutVariables() const;
	

private:
	std::unordered_map<std::string, std::vector<std::string>> varMap;
	std::unordered_map<std::string, std::shared_ptr<BuildStatement>> buildMap;
	std::unordered_map<std::string, std::shared_ptr<FunctionDefinition>> funMap;
	std::unique_ptr<Expression> functionCallResult;
};