#include "Token.h"



Token::Token()
{
}


Token::~Token()
{
}


Token Token::ofType(Type type) {
	Token t;
	t.type = type;
	return t;
}

std::string Token::toString(Token::Type type) {
	switch (type) {
	case Token::Type::Eof: return "Eof";
	case Token::Type::FileIdentifier: return "File identifier";
	case Token::Type::NameIdentifier: return "Name identifier";
	case Token::Type::VariableIdentifier: return "Variable identifier";
	case Token::Type::If: return "IF";
	case Token::Type::Else: return "ELSE";
	case Token::Type::For: return "FOR";
	case Token::Type::In: return "IN";
	case Token::Type::AssignmentOperator: return "Assignment operator";
	case Token::Type::String: return "String";
	case Token::Type::Colon: return "Colon";
	case Token::Type::OpenBracket: return "Open bracket";
	case Token::Type::CloseBracket: return "Close bracket";
	case Token::Type::OpenBrace: return "Open brace";
	case Token::Type::CloseBrace: return "Close brace";
	case Token::Type::AndOperator: return "And operator";
	case Token::Type::OrOperator: return "Or operator";
	case Token::Type::EqualOperator: return "Equal operator";
	case Token::Type::BuildOperator: return "Build operator";

	default: return "Unknown token type";
	}
}

Token Token::createSimpleToken(Type type)
{
	if (type == Token::Type::FileIdentifier
		|| type == Token::Type::NameIdentifier
		|| type == Token::Type::VariableIdentifier
		|| type == Token::Type::String)
		throw new std::runtime_error("Invalid type");
	else
		return ofType(type);
}

