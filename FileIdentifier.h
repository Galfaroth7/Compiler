#pragma once
#include "Expression.h"
class FileIdentifier :
	public Expression
{
public:
	FileIdentifier(std::unique_ptr<Expression> val, std::string& ext) : value(std::move(val)), extension(ext) {}
	~FileIdentifier();

	//std::string variable() const override {
	//	return value;
	//}

	virtual Type getType() const override {
		return Type::FILE;
	}

private:
	std::unique_ptr<Expression> value;
	std::string extension;


};

