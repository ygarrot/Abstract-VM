/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:04:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/27 16:05:13 by ygarrot          ###   ########.fr       */
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
	bool is_end;

	fs.open (toParse);
	if (!fs.is_open())
		return ;

	while (getline(fs, nl, '\n')) {
		nl = std::regex_replace (nl, std::regex(COMMENT),"$1");
		nl = std::regex_replace (nl, std::regex(COMMENT2),"");
		is_end = (regex_match(s, std::regex(END)));
		/* std::cout << "[" + nl  + "]" << "\n"; */ 
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
				std::cout << s << "\n";
				throw UnkownInstructionException();
			}
			_tokens.push_back(std::shared_ptr<Token>(new Token(token_type, s)));
		}
		if (is_end)
			return ;
	}
	/* std::cout << _tokens.size() << std::endl; */
}
