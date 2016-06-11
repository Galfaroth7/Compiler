#include "VariablesMap.h"


bool VariablesMap::containsVariable(const std::string& varname) const
{
	return varMap.count(varname) > 0;
}

void VariablesMap::storeVariable(const std::string& varname, const std::vector<std::string> value)
{
	varMap[varname] = value;
}

void VariablesMap::eraseVariable(const std::string& varname)
{
	varMap.erase(varname);
}

std::vector<std::string> VariablesMap::getVariable(const std::string& key) const
{
	auto var = varMap.find(key);
	if (var == varMap.end())
		throw std::runtime_error("Unknown variable " + key);
	return var->second;
}

void VariablesMap::storeFunction(const std::string& funName, const std::shared_ptr<FunctionDefinition>& value)
{
	funMap[funName] = value;
}

std::shared_ptr<FunctionDefinition> VariablesMap::getFunction(const std::string& key) const
{
	auto var = funMap.find(key);
	if (var == funMap.end())
		throw std::runtime_error("Unknown function " + key);
	return var->second;
}

std::shared_ptr<BuildStatement> VariablesMap::getBuildStatement(const std::string& key)
{
	auto var = buildMap.find(key);
	if (var == buildMap.end())
		throw std::runtime_error("Unknown function " + key);
	return var->second;
}

bool VariablesMap::buildExists(const std::string& key)
{
	auto var = buildMap.find(key);
	if (var == buildMap.end())
		return false;
	return true;
}

void VariablesMap::storeBuildStatement(const std::string& key,std::shared_ptr<BuildStatement>& build)
{
	buildMap[key] = build;
}

std::unique_ptr<Expression> VariablesMap::getCallResult() {
	return std::move(functionCallResult);
}

VariablesMap VariablesMap::withoutVariables() const {
	VariablesMap map;
	//map.varMap = varMap;
	map.funMap = funMap;
	map.buildMap = buildMap;
	return map;
}