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
		UnknownToken,
		Dot,
		Quote,
		True,
		False,
		FunctionCallMarker,
	};

	
	Token();
	~Token();
	Token(std::string);

	const Type getType() { return type; }
	const std::string getStringValue() { return stringValue; }

	static std::string toString(Type);
	static Token ofType(Type);
	static Token createSimpleToken(Type);
	static Token createStringToken(std::string, Type);

private:
	Type type;
	std::string stringValue;


};

inline std::ostream& operator<<(std::ostream& o, const Token::Type type) {
	return o << Token::toString(type);
}
