#pragma once
#include <istream>
#include <ostream>
#include <string>

class Token
{
public:

	enum class Type
	{
		Eof,
		FileIdentifier,
		NameIdentifier,
		VariableIdentifier,
		If,
		Else,
		For,
		In,
		Colon,
		OpenBracket,
		CloseBracket,
		OpenBrace,
		CloseBrace,
		AssignmentOperator,
		AndOperator,
		OrOperator,
		EqualOperator,
		BuildOperator,
		String,
	};

	
	Token();
	~Token();
	Token(std::string);

	Type getType() { return type; }
	std::string getStringValue() { return stringValue; }

	static std::string toString(Type);
	static Token ofType(Type);
	static Token createSimpleToken(Type);

private:
	Type type;
	std::string stringValue;


};

inline std::ostream& operator<<(std::ostream& o, const Token::Type type) {
	return o << Token::toString(type);
}
