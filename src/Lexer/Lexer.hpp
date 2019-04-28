/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:03:50 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 17:44:08 by ygarrot          ###   ########.fr       */
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
#define END "(.*)(;;.*$)"
#define COMMENT "(.*[^;])(;.*$)"
#define COMMENT2 "(;.*$)"
#define VALUE \
	"int8\\(("   DIGIT ")\\)|"\
	"int16\\(("  DIGIT ")\\)|"\
	"int32\\(("  DIGIT ")\\)|"\
	"double\\((" IMA   ")\\)|"\
	"float\\(("  IMA   ")\\)|"

#define INSTRUCTION \
		"push" \
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

#define DIGIT "[-]?[0-9]+"

#define IMA "[-]?[0-9]+.[0-9]+"

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
		void		lex(std::string toParse);
		bool		setToken(std::string nl);
		TOKEN_PTR	get_tokens(){return _tokens;};
	private:
		int			_lines;
		TOKEN_PTR	_tokens;
};
/* std::ostream 		&operator<<(std::ostream & o, Lexer const & src); */

#endif
