#include "Scanner.h"



Scanner::Scanner(std::istream& in_)
	: in(in_)
{
}

bool Scanner::isIdentifierSign(char c)
{
	return (std::isalnum(c) || c == '+' || c == '-' || c == '_');
}

void Scanner::ignoreWhitespaces()
{
	while (in && std::isspace(in.peek()))
	{
		if (in.peek() == '\n')
			currentLine++;
		in.get();
	}
}

void Scanner::readNextToken()
{
	ignoreWhitespaces();
	if (tokenFound())
		return;
	in.get();
	token = Token::createSimpleToken(Token::Type::UnknownToken);
	return;
}


bool Scanner::tokenFound()
{
	return tryEof()
		|| tryParentheses()
		|| tryAndOperator()
		|| tryOrOperator()
		|| tryEqualOperator()
		|| tryAssignmentOperator()
		|| tryColon()
		|| tryBuildOperator()
		|| tryVariableIdentifier()
		|| tryKeywordOrNameIdentifier();
}

Token Scanner::getToken() const
{
	return token;
}

std::string Scanner::readString()
{
	std::string buf;
	while (in && isIdentifierSign(in.peek()))
		buf += static_cast<char>(in.get());
	return buf;
}

bool Scanner::tryColon()
{
	if (in.peek() != ':')
		return false;
	in.get();
	token = Token::createSimpleToken(Token::Type::Colon);
	return true;
}

bool Scanner::tryParentheses()
{
	switch (in.peek())
	{
	case '(':
		in.get();
		token = Token::createSimpleToken(Token::Type::OpenBracket);
		break;
	case ')':
		in.get();
		token = Token::createSimpleToken(Token::Type::CloseBracket);
		break;
	case '{':
		in.get();
		token = Token::createSimpleToken(Token::Type::OpenBrace);
		break;
	case '}':
		in.get();
		token = Token::createSimpleToken(Token::Type::CloseBrace);
		break;
	default:
		return false;
	}
	return true;
}


bool Scanner::tryKeywordOrNameIdentifier()
{
	std::string buf, buf2;
	buf = readString();

	if (buf == "if")
		token = Token::createSimpleToken(Token::Type::If);
	else if (buf == "else")
		token = Token::createSimpleToken(Token::Type::Else);
	else if (buf == "for")
		token = Token::createSimpleToken(Token::Type::For);
	else if (buf == "in")
		token = Token::createSimpleToken(Token::Type::In);
	else if (in.peek() == '.')
	{
		in.get();
		buf += ".";
		buf2 += readString();
		if (!buf2.empty())
		{
			buf += buf2;
			token = Token::createStringToken(buf, Token::Type::FileIdentifier);
		}

		else return false;
	}
	else if (!buf.empty())
	{
		token = Token::createStringToken(buf, Token::Type::NameIdentifier);
	}
	else return false;

	return true;
}


bool Scanner::tryVariableIdentifier()
{
	std::string buf, buf2, buf3;
	if (in.peek() != '$')
		return false;
	in.get();
	buf += "$";
	buf3 += readString();
	if (!buf3.empty())
		if (in.peek() != '.')
		{
			buf += buf3;
			token = Token::createStringToken(buf, Token::Type::VariableIdentifier);
			return true;
		}
		else
		{
			buf += buf3;
			in.get();
			buf += ".";
			buf2 += readString();
			if (!buf2.empty())
			{
				buf += buf2;
				token = Token::createStringToken(buf, Token::Type::FileIdentifier);
				return true;
			}

			else return false;
		}
	else return false;
	
}

bool Scanner::tryAssignmentOperator()
{
	if (in.peek() != '=')
		return false;
	in.get();
	token = Token::createSimpleToken(Token::Type::AssignmentOperator);
	return true;
}

bool Scanner::tryAndOperator()
{
	if (in.peek() != '&')
		return false;
	in.get();
	if (in.peek() != '&')
	{
		in.putback('&');
		return false;
	}
	in.get();
	token = Token::createSimpleToken(Token::Type::AndOperator);
	return true;

}

bool Scanner::tryOrOperator()
{
	if (in.peek() != '|')
		return false;
	in.get();
	if (in.peek() != '|')
	{
		in.putback('|');
		return false;
	}
	in.get();
	token = Token::createSimpleToken(Token::Type::OrOperator);
	return true;

}

bool Scanner::tryEqualOperator()
{
	if (in.peek() != '=')
		return false;
	in.get();
	if (in.peek() != '=')
	{
		in.putback('=');
		return false;
	}
	in.get();
	token = Token::createSimpleToken(Token::Type::EqualOperator);
	return true;

}

bool Scanner::tryBuildOperator()
{
	if (in.peek() != '-')
		return false;
	in.get();
	if (in.peek() != '>')
	{
		in.putback('-');
		return false;
	}
	in.get();
	token = Token::createSimpleToken(Token::Type::BuildOperator);
	return true;

}

bool Scanner::tryEof()
{
	if (!in.eof())
		return false;
	token = Token::createSimpleToken(Token::Type::Eof);
	return true;
}

//bool Scanner::tryCloseBrace()
//{
//	if (in.peek != '}')
//		return false;
//	in.get();
//	token = Token::createSimpleToken(Token::Type::CloseBrace);
//	return true;
//}
//





