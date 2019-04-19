/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:04:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 16:42:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Lexer.hpp"

Lexer::Lexer(std::string target) 
{
	(void)target;
}

Lexer::Lexer() 
{
	std::string Values = {
	"int8\\("   N "\\)",
	"int16\\("  N "\\)",
	"int32\\("  N "\\)",
	"double\\(" Z "\\)",
	"float\\("  Z "\\)",
	};
	/* std::string Values.join("|"); */
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

void Lexer::Lex(std::string toParse)
{
	std::istringstream f(toParse);
	std::string s;

	while (getline(f, s, ' ')) {
		/* if ( */
	}
}
