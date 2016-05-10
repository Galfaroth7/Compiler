

#include "Scanner.h"
#include "Token.h"
#include <iostream>
#include <sstream>




int main()
{

	std::istringstream in("{} () && = == ||       ");
	Scanner scanner(in);

	do
	{
		scanner.readNextToken();
		Token token;
		token = scanner.getToken();
		std::cout << token.getType() << std::endl;
	} while (scanner.getToken().getType() != Token::Type::Eof);
	return 0;
}