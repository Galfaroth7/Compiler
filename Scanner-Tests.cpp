//
//#define BOOST_TEST_MODULE ScannerTests
//#include <boost/test/unit_test.hpp>
//#include <sstream>
//#include "Scanner.h"
//
//
//
//BOOST_AUTO_TEST_CASE(eof_on_empty)
//{
//	std::istringstream in;
//	Scanner scanner(in);
//
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::Eof, scanner.getToken().getType());
//}
//
//
//BOOST_AUTO_TEST_CASE(brackets)
//{
//	std::istringstream in("()");
//	Scanner scanner(in);
//	scanner.readNextToken();
//	auto firstToken = scanner.getToken();
//	scanner.readNextToken();
//	auto secondToken = scanner.getToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::OpenBracket, firstToken.getType());
//	BOOST_CHECK_EQUAL(Token::Type::CloseBracket, secondToken.getType());
//}
//
//BOOST_AUTO_TEST_CASE(braces)
//{
//	std::istringstream in("{}");
//	Scanner scanner(in);
//	scanner.readNextToken();
//	auto first = scanner.getToken();
//	scanner.readNextToken();
//	auto second = scanner.getToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::OpenBrace, first.getType());
//	BOOST_CHECK_EQUAL(Token::Type::CloseBrace, second.getType());
//}
//
//BOOST_AUTO_TEST_CASE(buildOp)
//{
//	std::istringstream in("->");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::BuildOperator, scanner.getToken().getType());
//	
//}
//
//BOOST_AUTO_TEST_CASE(andOp)
//{
//	std::istringstream in("&&");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::AndOperator, scanner.getToken().getType());
//
//}
//
//BOOST_AUTO_TEST_CASE(orOp)
//{
//	std::istringstream in("||");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::OrOperator, scanner.getToken().getType());
//
//}
//
//
//BOOST_AUTO_TEST_CASE(nameId)
//{
//	std::istringstream in("test123");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::NameIdentifier, scanner.getToken().getType());
//
//}
//
//
//BOOST_AUTO_TEST_CASE(variableId)
//{
//	std::istringstream in("$test123");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::VariableIdentifier, scanner.getToken().getType());
//}
//
//
//BOOST_AUTO_TEST_CASE(equalOp)
//{
//	std::istringstream in("==");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::EqualOperator, scanner.getToken().getType());
//}
//
//
//BOOST_AUTO_TEST_CASE(assignOp)
//{
//	std::istringstream in("=");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::AssignmentOperator, scanner.getToken().getType());
//}
//
//BOOST_AUTO_TEST_CASE(colon)
//{
//	std::istringstream in(":");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::Colon, scanner.getToken().getType());
//}
//
//BOOST_AUTO_TEST_CASE(dot)
//{
//	std::istringstream in(".");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::Dot, scanner.getToken().getType());
//}
//
//
//BOOST_AUTO_TEST_CASE(quote)
//{
//	std::istringstream in("\"");
//	Scanner scanner(in);
//	scanner.readNextToken();
//
//	BOOST_CHECK_EQUAL(Token::Type::Quote, scanner.getToken().getType());
//}
//
//BOOST_AUTO_TEST_CASE(lotOfWhitespaces)
//{
//	std::istringstream in("      \t\t\t\t\t\t\n\n\n\n\n            test.txt \n\n\n\n");
//	Scanner scanner(in);
//	scanner.readNextToken();
//	auto firstToken = scanner.getToken();
//	scanner.readNextToken();
//	auto secondToken = scanner.getToken();
//	scanner.readNextToken();
//	auto thirdToken = scanner.getToken();
//	BOOST_CHECK_EQUAL(Token::Type::NameIdentifier, firstToken.getType());
//	BOOST_CHECK_EQUAL(Token::Type::Dot, secondToken.getType());
//	BOOST_CHECK_EQUAL(Token::Type::NameIdentifier, thirdToken.getType());
//}