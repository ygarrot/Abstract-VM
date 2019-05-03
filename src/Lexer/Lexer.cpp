/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:04:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/03 11:13:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Lexer.hpp"

Lexer::Lexer() :_lines(-1)
{
}

Lexer::~Lexer() 
{

}

Lexer::Lexer(Lexer const &src)
{
	_tokens = src._tokens;
	_lines = src._lines;
	*this = src;
}

Lexer     &Lexer::operator=(Lexer const & src) 
{
	_tokens = src._tokens;
	_lines = src._lines;
	return *this;
}

bool Lexer::setToken(std::string nl)
{
	TokenType	token_type;
	std::string s;
	bool is_end;

	_lines++;
	is_end = !regex_match(nl, std::regex(END));
	nl = std::regex_replace (nl, std::regex(COMMENT),"$1");
	nl = std::regex_replace (nl, std::regex(COMMENT2),"");
	nl  = std::regex_replace(nl, std::regex("\\s+"), " ");
	std::stringstream ss(nl);
	while (getline(ss, s, ' '))
	{
		s = std::regex_replace(s, std::regex("\\s+"), "");
		if (s.empty())
			continue;
		/* std::cout << "[" + s+  "]"<< std::endl; */
		if (regex_match(s, std::regex(INSTRUCTION)))
		{
			token_type = TokenType::Instruction;
		}
		else if (regex_match(s, std::regex(VALUE)))
		{
			token_type = TokenType::Value;
		}
		else
		{
			throw UnknownInstructionException(_lines);
		}
		_tokens.push_back(std::shared_ptr<Token>(new Token(token_type, s, _lines)));
	}
	return is_end;
}

int Lexer::lex()
{
	int ret = 1;

	for (std::string line; std::getline(std::cin, line);)
	{
		try {
			if (!setToken(line)) return 1;
		}
		catch (TokenException & e)
		{
			std::cout << e.what() << "\n";
			ret = -1;
		}
	}
	return ret;
}

int Lexer::lex(std::string toParse)
{
	int ret = 1;
	std::istringstream f(toParse);
	std::ifstream fs;
	std::string nl;

	fs.open (toParse);
	if (!fs.good() || !fs.is_open())
		throw InvalidFileException();
	while (getline(fs, nl, '\n'))
	{
		try {
			if (!setToken(nl)) return 1;
		}
		catch (TokenException & e)
		{
			std::cout << e.what() << "\n";
			ret = -1;
		}
	}
	return ret;
}
