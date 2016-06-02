

#include "Scanner.h"
#include "Token.h"
#include "Parser.h"
#include <iostream>
#include <sstream>
#include <cstdlib>


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
	case Token::Type::Eof: std::cout << "EOF"; break;
	case Token::Type::Dot: std::cout << "."; break;
	case Token::Type::Quote: std::cout << "\""; break;
	case Token::Type::UnknownToken: std::cout << "Unknown"; break;
	default: std::cout << t.getStringValue();
	}
	std::cout << std::endl << std::endl;
}


int main()
{

	//std::istringstream in("my_fun($a){ for($b in $list) { hello: $b -> \"g++ -c hello.c\" } }  $a = windows \n $b = linux \n hello: {hello.cpp hello.h} -> \"g++ -c hello.c\" if($a == window && $b == linux && $c == unix ) hello: {hello.cpp hello.h} -> \"g++ -c hello.c\"");
	//Parser parser(in);
	//parser.parse();
	system("echo Jestem");
	return 0;
}