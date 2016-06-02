#include "Parser.h"

/*
<alphanumeric>::=<literal>|<numeral>|<other_sings>
<name_identifier>::=<alphanumeric>|<name_identifier><alphanumeric>
<variable_identifier>::='$'<name_identifier>
<file_identifier>::=<name_identifier>'.'<name_identifier> | <variable_identifier>'.'<name_identifier>
<identifier>::=<name_identifier> | <variable_identifier> | <file_identifier>
<identifier_list>::= <identifier> | <identifier><identifier_list>

<assignment>::=<identifier_assignment> | <boolean_assignment> | <list_assignment>
<assignments>::= <assignment> { <assignment> }
<identifier_assignment>::=<variable_identifier>'='<name_identifier>
<boolean_assignment>::=<variable_identifier>'='<boolean_value>
<list_assignment>::=<variable_identifier>'=''{'<identifier_list>'}'
<string_ assignment>::=<variable_identifier>'=’<string>  <---- do wywalenia, bo po co przypisywaæ zmienn¹ do stringa

<or_expression>::=<and_expression> { '||' <and_expression> }
<and_expression>::=<compare_expression> { '&&' <compare_expression> }
<compare_expression>::=<variable_identifier>'=='<name_identifier> | '('<or_expression>')'

<selection> ::= 'if' '(' <expression> ')' <statement> <optional_else>,,,
<optional_else> ::= 'else' <statement> | <empty>
<loop>::='for''('<variable_identifier>'in'<variable_identifier>')'<statement> | 'for''('<variable_identifier>'in'<list>')'<statement>

<string>::='"'<identifier_list>'"'
<block>::='{' <statements> '}'
<statements>::= <statements> <statement> | <statement>
<statement>::=<build_statement> | <loop> | <selection>  | <function_call> | <block>
<list> ::= '{'<identifier_list>'}'

<build_statement>::=<target>':'<dependecies>'->'<string>
<target>::=<identifier>
<dependecies>::=<variable_identifier> | '{'<identifier_list>'}'
<function_definition>::=<name_identifier>'('<identifier_list>')'<statement>
<function_call>::=@<name_identifier>'('<identifier_list>')'
*/

 /*
 Zak³adam, ¿e dependencje w poleceniu budowania to tylko te pliki, które musz¹ siê zbudowaæ przed
 zbudowaniem pliku docelowego w danym poleceniu.

 */


Parser::~Parser()
{
}


Token Parser::requireToken(Token::Type expected)
{
	auto token = scanner.getToken();
	auto type = token.getType();
	if (type != expected)
		throwOnUnexpectedInput(expected);
	advance();
	return token;
}

bool Parser::checkTokenType(Token::Type expected) const
{
	return scanner.getToken().getType() == expected;
}

void Parser::advance()
{
	currentToken = scanner.getToken();
	scanner.readNextToken();
}

void Parser::throwOnUnexpectedInput(Token::Type expected)
{
	throw std::runtime_error("Failure");
}

std::unique_ptr<Expression> Parser::getIdentifierIfDot(std::unique_ptr<Expression> name)
{
	if (checkTokenType(Token::Type::Dot))
	{
		advance();
		auto extension = requireToken(Token::Type::NameIdentifier).getStringValue();
		return std::make_unique<FileIdentifier>(std::move(name), extension);
	}
	return name;
}


std::unique_ptr<Expression> Parser::createIdentifierName(Token::Type type)
{
	if (type == Token::Type::NameIdentifier)
		return std::make_unique<NameIdentifier>(currentToken.getStringValue());
	else
		return std::make_unique<VariableIdentifier>(currentToken.getStringValue());
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************

std::vector<std::unique_ptr<Statement>> Parser::parseAssignments()
{
	std::vector<std::unique_ptr<Statement>> assignments;
	while (checkTokenType(Token::Type::VariableIdentifier))
		assignments.push_back(parseAssignment());
	return assignments;
}

std::vector<std::unique_ptr<Statement>> Parser::parseFunctionDefinitions()
{
	std::vector<std::unique_ptr<Statement>> definitions;
	while (checkTokenType(Token::Type::NameIdentifier))
		definitions.push_back(parseFunctionDefinition());
	return definitions;
}

std::vector<std::unique_ptr<Statement>> Parser::parseStatements()
{
	std::vector<std::unique_ptr<Statement>> statements;
	while (checkTokenType(Token::Type::For)
			|| checkTokenType(Token::Type::If)
			|| checkTokenType(Token::Type::NameIdentifier)
			|| checkTokenType(Token::Type::OpenBrace))
		statements.push_back(parseStatement());
	return statements;
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************



std::unique_ptr<Expression> Parser::parseOrExpression()
{
	auto left = parseAndExpression();
	if (checkTokenType(Token::Type::OrOperator))
	{	
		advance();
		auto right = parseAndExpression();
		return std::make_unique<BinaryExpression>(std::move(left), Expression::BinaryOperator::OR, std::move(right));
	}
}

std::unique_ptr<Expression> Parser::parseAndExpression()
{

	//Sprawdziæ czy bedzie dzialac z  ifem
	auto left = parseCompareExpression();
	if (checkTokenType(Token::Type::AndOperator))
	{	
		advance();
		auto right = parseCompareExpression();
		return std::make_unique<BinaryExpression>(std::move(left), Expression::BinaryOperator::AND, std::move(right));
	}
}

std::unique_ptr<Expression> Parser::parseCompareExpression()
{
	if (checkTokenType(Token::Type::OpenBracket))
	{
		requireToken(Token::Type::OpenBracket);
		auto expression = parseOrExpression();
		requireToken(Token::Type::CloseBracket);
		return std::move(expression);
	}
	else
	{
		auto left = std::make_unique<VariableIdentifier>(requireToken(Token::Type::VariableIdentifier).getStringValue());
		requireToken(Token::Type::EqualOperator);
		auto right = std::make_unique<NameIdentifier>(requireToken(Token::Type::NameIdentifier).getStringValue());
		return std::make_unique<BinaryExpression>(std::move(left), Expression::BinaryOperator::EQUAL, std::move(right));
	}
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************

std::unique_ptr<Statement> Parser::parseStatement()
{
	if (checkTokenType(Token::Type::For))
		return parseLoop();
	if (checkTokenType(Token::Type::If))
		return parseSelection();
	if (checkTokenType(Token::Type::OpenBrace))
		return parseBlock();
	if (checkTokenType(Token::Type::FunctionCallMarker))
		return parseFunctionCall();
	return parseBuildStatement();
}

std::unique_ptr<Statement>  Parser::parseSelection()
{
	requireToken(Token::Type::If);
	requireToken(Token::Type::OpenBracket);
	auto condition = parseOrExpression();
	requireToken(Token::Type::CloseBracket);
	auto ifBlock = parseStatement();
	if (scanner.getToken().getType() == Token::Type::Else)
	{
		advance();
		auto elseBlock = parseStatement();
		return std::make_unique<Selection>(std::move(condition), std::move(ifBlock), std::move(elseBlock));
	}
	return std::make_unique<Selection>(std::move(condition), std::move(ifBlock));
}

std::unique_ptr<Statement> Parser::parseLoop()
{
	std::unique_ptr<Expression> collection;

	requireToken(Token::Type::For);
	requireToken(Token::Type::OpenBracket);
	auto element = std::make_unique<VariableIdentifier>(requireToken(Token::Type::VariableIdentifier).getStringValue()); 
	requireToken(Token::Type::In);
	if (checkTokenType(Token::Type::OpenBrace))
		collection = parseList();
	else
		collection	= std::make_unique<VariableIdentifier>(requireToken(Token::Type::VariableIdentifier).getStringValue());
	requireToken(Token::Type::CloseBracket);
	auto block = parseStatement();
	return std::make_unique<Loop>(std::move(element), std::move(collection), std::move(block));
}


std::unique_ptr<Statement> Parser::parseBlock()
{
	requireToken(Token::Type::OpenBrace);
	auto statements = parseStatements();
	requireToken(Token::Type::CloseBrace);
	return std::make_unique<Block>(statements);
}

std::unique_ptr<Statement> Parser::parseFunctionCall()
{
	auto functionName = std::make_unique<NameIdentifier>(requireToken(Token::Type::NameIdentifier).getStringValue());
	auto arguments = parseIdentifierList();
	return std::make_unique<FunctionCall>(std::move(functionName), std::move(arguments));
}


std::unique_ptr<Statement> Parser::parseBuildStatement()
{
	std::unique_ptr<Expression> dependencies;
	
	if (checkTokenType(Token::Type::NameIdentifier) || checkTokenType(Token::Type::VariableIdentifier))
	{
		advance();
		auto name = createIdentifierName(currentToken.getType());
		auto target = getIdentifierIfDot(std::move(name));
		
		requireToken(Token::Type::Colon);
		
		if (checkTokenType(Token::Type::OpenBrace))
			dependencies = parseList();
		else
			dependencies = std::make_unique<VariableIdentifier>(requireToken(Token::Type::VariableIdentifier).getStringValue());
		
		requireToken(Token::Type::BuildOperator);
		auto buildCommand = parseString();
		return std::make_unique<BuildStatement>(std::move(target), std::move(dependencies), std::move(buildCommand));
	}
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************


std::unique_ptr<Statement> Parser::parseFunctionDefinition()
{
	auto functionName = std::make_unique<NameIdentifier>(requireToken(Token::Type::NameIdentifier).getStringValue());
	auto arguments = parseIdentifierList();
	auto body = parseStatement();
	return std::make_unique<FunctionDefinition>(std::move(functionName), std::move(arguments), std::move(body));
}

std::unique_ptr<Statement> Parser::parseAssignment()
{
	std::unique_ptr<Expression> assignable;
	auto varName = std::make_unique<VariableIdentifier>(requireToken(Token::Type::VariableIdentifier).getStringValue());
	requireToken(Token::Type::AssignmentOperator);
	if (checkTokenType(Token::Type::OpenBrace))
		assignable = parseList();
	else if (checkTokenType(Token::Type::Quote))
		assignable = parseString();
	else
	{
		auto name = std::make_unique<NameIdentifier>(requireToken(Token::Type::NameIdentifier).getStringValue());
		assignable = getIdentifierIfDot(std::move(name));
	}
	return std::make_unique<Assignment>(std::move(varName), std::move(assignable));
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************


std::vector<std::unique_ptr<Expression>> Parser::parseIdentifierList()
{
	std::vector<std::unique_ptr<Expression>> identifiers;

	while (checkTokenType(Token::Type::NameIdentifier) || checkTokenType(Token::Type::VariableIdentifier))
	{
		advance();
		auto name = createIdentifierName(currentToken.getType());
		identifiers.push_back(getIdentifierIfDot(std::move(name)));
	}
	return std::move(identifiers);
}

std::unique_ptr<String> Parser::parseString()
{
	requireToken(Token::Type::Quote);
	auto identifierList = parseIdentifierList();
	requireToken(Token::Type::Quote);
	return std::make_unique<String>(std::move(identifierList));
}

std::unique_ptr<List> Parser::parseList()
{
	requireToken(Token::Type::OpenBrace);
	auto identifierList = parseIdentifierList();
	requireToken(Token::Type::CloseBrace);
	return std::make_unique<List>(std::move(identifierList));
}

//**********************************************************************************************
//**********************************************************************************************
//**********************************************************************************************


void Parser::parse()
{
	advance();
	parseFunctionDefinitions();
	parseAssignments();
	parseStatements();
}
