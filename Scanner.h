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
	bool tryVariableIdentifier();
	bool tryKeywordOrNameIdentifier();
	bool tryColon();
	bool tryDot();
	bool tryParentheses();
	bool tryAssignmentOperator();
	bool tryAndOperator();
	bool tryOrOperator();
	bool tryEqualOperator();
	bool tryBuildOperator();
	bool tryQuote();
	bool tryFunctionCallMarker();
	std::istream& in;
	Token token;
	unsigned int currentLine = 1;
	std::string readCharachterStream();
};



