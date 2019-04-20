/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:03:50 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 15:11:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>

/* #define S INSTRUCTION [SEP INSTRUCTION]* # */
#define VALUE \
	"int8\\(("   N ")\\)|"\
	"int16\\(("  N ")\\)|"\
	"int32\\(("  N ")\\)|"\
	"double\\((" Z ")\\)|"\
	"float\\(("  Z ")\\)|"

#define INSTRUCTION \
		"push"\
	"|" "pop"\
	"|" "dump"\
	"|" "assert"\
	"|" "add"\
	"|" "sub"\
	"|" "mul"\
	"|" "div"\
	"|" "mod"\
	"|" "print"\
	"|" "exit"

#define N "[-]?[0-9]+"

#define Z "[-]?[0-9]+.[0-9]+"

#define SEP "[\\n]+"

#define TOKEN_PTR std::vector< std::shared_ptr<Token> >

class 					Lexer
{
	public:
		~Lexer(void);
		Lexer(void);
		Lexer(std::string name);
		Lexer(Lexer const &src);
		Lexer 		&operator=(Lexer const & src);
		void lex(std::string toParse);
		TOKEN_PTR get_tokens(){return _tokens;};
	private:
		TOKEN_PTR _tokens;
};
/* std::ostream 		&operator<<(std::ostream & o, Lexer const & src); */

#endif
