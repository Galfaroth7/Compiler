

#include "Scanner.h"
#include "Token.h"
#include <iostream>
#include <sstream>


void printValue(Token& t) {
	std::cout << "Value: ";
	switch (t.getType()) {
	case Token::Type::AndOperator: std::cout << "&&"; break;
	case Token::Type::AssignmentOperator: std::cout << "="; break;
	case Token::Type::BuildOperator: std::cout << "->"; break;
	case Token::Type::Colon: std::cout << ":"; break;
	case Token::Type::OpenBrace: std::cout << "{"; break;
	case Token::Type::CloseBrace: std::cout << "}"; break;
	case Token::Type::OpenBracket: std::cout << "("; break;
	case Token::Type::CloseBracket: std::cout << ")"; break;
	case Token::Type::OrOperator: std::cout << "||"; break;
	case Token::Type::For: std::cout << "for"; break;
	case Token::Type::If: std::cout << "if"; break;
	case Token::Type::Else: std::cout << "else"; break;
	case Token::Type::In: std::cout << "in"; break;
	case Token::Type::EqualOperator: std::cout << "=="; break;
	case Token::Type::Eof: std::cout << "EOF";
	case Token::Type::UnknownToken: std::cout << "Unknown"; break;
	default: std::cout << t.getStringValue();
	}
	std::cout << std::endl << std::endl;
}

//   && || -> == = : cos.wwwiu

int main()
{

	std::istringstream in("$$ $value $value.txt asdf in for else if () {} ][");
	Scanner scanner(in);
	do
	{
		scanner.readNextToken();
		Token token;
		token = scanner.getToken();
		std::cout << token.getType() << std::endl;
		printValue(token);
	} while (scanner.getToken().getType() != Token::Type::Eof);
	return 0;
}