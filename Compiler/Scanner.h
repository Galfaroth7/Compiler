#pragma once
#include <istream>
#include <cctype>

#include "Token.h"

class Scanner
{
public:
	Scanner(std::istream& in);

	Scanner(const Scanner&) = delete;
	const Scanner& operator=(const Scanner&) = delete;

	void readNextToken();
	Token getToken() const;
	int getCurrentLine() { return currentLine; }


private:

	void ignoreWhitespaces();
	std::string readString();
	bool isIdentifierSign(char);
	bool tokenFound();
	bool tryEof();
	bool tryFileIdentfier();
	bool tryVariableIdentifier();
	bool tryNameIdentifier();
	bool tryKeyword();
	bool tryColon();
	bool tryParentheses();
	bool tryAssignmentOperator();
	bool tryAndOperator();
	bool tryOrOperator();
	bool tryEqualOperator();
	bool tryBuildOperator();
	bool tryString();
	std::istream& in;
	Token token;
	unsigned int currentLine = 1;
	std::string readCharachterStream();
};

/*bool tryIf();
bool tryElse();
bool tryFor();
bool tryIn();*/

/*bool tryOpenBracket();
bool tryCloseBracket();
bool tryOpenBrace();
bool tryCloseBrace();*/

