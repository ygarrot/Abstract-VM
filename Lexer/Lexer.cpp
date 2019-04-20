/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:04:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 13:24:40 by ygarrot          ###   ########.fr       */
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

void Lexer::lex(std::string toParse)
{
	std::istringstream f(toParse);
	std::ifstream fs;
	std::string nl;
	std::string s;
	TokenType	token_type;

	fs.open (toParse);
	if (!fs.is_open())
		return ;

	while (getline(fs, nl, '\n')) {

		std::stringstream ss(nl);
		while (getline(ss, s, ' '))
		{
			if (regex_match(s, std::regex(INSTRUCTION)))
			{
				/* std::cout << "INSTR" << std::endl; */
				token_type = TokenType::Instruction;
			}
			else if (regex_match(s, std::regex(VALUE)))
			{
				/* std::cout << "VALUE" << std::endl; */
				token_type = TokenType::Value;
			}
			else
			{
				/* std::cout << "Error : [" << s<< "]" << std::endl; */
				/* token_type = token_type::Instruction; */
			}
			_tokens.push_back(std::shared_ptr<Token>(new Token(token_type, s)));
		}
		_tokens.push_back(std::shared_ptr<Token>(new Token(TokenType::Sep, s)));
	}
	std::cout << _tokens.size() << std::endl;
}
