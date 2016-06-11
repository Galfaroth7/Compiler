
#pragma once
#include "Scanner.h"
#include "VariableIdentifier.h"
#include "FileIdentifier.h"
#include "NameIdentifier.h"
#include "String.h"
#include "List.h"
#include "BinaryExpression.h"
#include "Statement.h"
#include "Selection.h"
#include "Loop.h"
#include "Block.h"
#include "FunctionDefinition.h"
#include "FunctionCall.h"
#include "Assignment.h"
#include "BuildStatement.h"
#include "ASTRootNode.h"

#include <vector>
#include <memory>
#include <iostream>

class Parser
{
public:
	Parser(std::istream& in) : scanner(in) {}
	~Parser();
	void parse();

private:	
	std::vector<std::unique_ptr<Statement>> parseAssignments();

	std::vector<std::unique_ptr<Expression>> parseIdentifierList();
	
	std::unique_ptr<Expression> parseOrExpression();
	std::unique_ptr<Expression> parseAndExpression();
	std::unique_ptr<Expression> parseCompareExpression();
	
	std::unique_ptr<Statement> parseSelection();
	std::unique_ptr<Statement> parseLoop();
	
	std::unique_ptr<String> parseString();
	std::unique_ptr<List> parseList();

	std::unique_ptr<Statement> parseBlock();
	std::unique_ptr<Statement> parseStatement();
	std::vector<std::unique_ptr<Statement>> parseStatements();
	std::unique_ptr<Statement> parseBuildStatement();


	std::vector<std::unique_ptr<Statement>> parseFunctionDefinitions();
	std::unique_ptr<Statement> parseFunctionDefinition();
	std::unique_ptr<Statement> parseFunctionCall();

	std::unique_ptr<Statement> parseAssignment();

	std::unique_ptr<Expression> getIdentifierIfDot(std::unique_ptr<Expression>);
	std::unique_ptr<Expression> createIdentifierName(Token::Type);

	Token requireToken(Token::Type expected);
	bool checkTokenType(Token::Type expected) const;

	void advance();
	void throwOnUnexpectedInput(Token::Type expected);
	Scanner scanner;
	Token currentToken;
};

