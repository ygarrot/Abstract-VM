/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:03:50 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 11:46:35 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include "../Operand/IOperand.hpp"

#include <sstream>
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>

/* #define S INSTRUCTION [SEP INSTRUCTION]* # */

enum class TokenType
{
	Instruction,
	Value,
	N,
	V,
	Sep
};

class Token
{
	public:
		Token(TokenType type, std::string str): _type(type), _str(str){};
		std::string get_str(){ return _str;};
		TokenType get_type(){ return _type;};
	private:
		TokenType _type;
		std::string _str;
		union content
		{
			std::shared_ptr<IOperand> op;
			union func
			{
				void (*method)(void);
				void (*f)(IOperand rhs);
			};
		};
};


#define VALUE \
	"int8\\("   N "\\)|"\
	"int16\\("  N "\\)|"\
	"int32\\("  N "\\)|"\
	"double\\(" Z "\\)|"\
	"float\\("  Z "\\)|"

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

#define N "[-]?[[:digit:]]+"

#define Z "[-]?[[:digit:]]+.[[:digit:]]+"

#define SEP "[\\n]+"

class 					Lexer
{
	public:
		~Lexer(void);
		Lexer(void);
		Lexer(std::string name);
		Lexer(Lexer const &src);
		Lexer 		&operator=(Lexer const & src);
		void lex(std::string toParse);
	private:
		std::vector< std::shared_ptr<Token> > _tokens;
};
/* std::ostream 		&operator<<(std::ostream & o, Lexer const & src); */

#endif
