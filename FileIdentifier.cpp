#include "FileIdentifier.h"

FileIdentifier::FileIdentifier(std::unique_ptr<Expression> val, std::string& ext) : value(std::move(val)), extension(ext) {}

FileIdentifier::~FileIdentifier()
{

}

std::vector<std::string> FileIdentifier::evaluate(VariablesMap& map)
{
	std::vector<std::string> valueEval = value->evaluate(map);
	if (valueEval.size() != 1)
	{
		//throw error
	}
	std::stringstream ss;
	std::string filename = *valueEval.begin();
	if (filename.find('.') == std::string::npos)
	{
		ss << filename << std::string(".") << extension;
		filename = ss.str();
	}
	valueEval.pop_back();
	valueEval.push_back(filename);
	return valueEval;
}