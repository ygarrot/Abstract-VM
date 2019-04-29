/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:04:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 12:34:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Lexer.hpp"

Lexer::Lexer(std::string target) 
{
	(void)target;
}

Lexer::Lexer() 
{
}

Lexer::~Lexer() 
{

}

Lexer::Lexer(Lexer const &src)
{
	*this = src;
}

Lexer     &Lexer::operator=(Lexer const & src) 
{
	(void)src;
	return *this;
}

bool Lexer::setToken(std::string nl)
{
	TokenType	token_type;
	std::string s;
	bool is_end;

	_lines++;
	is_end = !regex_match(s, std::regex(END));
	nl = std::regex_replace (nl, std::regex(COMMENT),"$1");
	nl = std::regex_replace (nl, std::regex(COMMENT2),"");
	std::stringstream ss(nl);
	while (getline(ss, s, ' '))
	{
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
	std::cout << is_end << "\n";
	return is_end;
}

void Lexer::lex()
{
	for (std::string line; std::getline(std::cin, line);)
	{
		if (!setToken(line + "\n")) return ;
	}
}

void Lexer::lex(std::string toParse)
{
	std::istringstream f(toParse);
	std::ifstream fs;
	std::string nl;

	fs.open (toParse);
	if (!fs.is_open())
		return ;

	while (getline(fs, nl, '\n'))
	{
		if (!setToken(nl)) return ;
	}
}
