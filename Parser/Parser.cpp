/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:37:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 15:11:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(std::string target) 
{
	(void)target;
}

Parser::Parser() 
{

}

Parser::~Parser() 
{

}

Parser::Parser(Parser const &src)
{
	*this = src;
}

Parser     &Parser::operator=(Parser const & src) 
{
	(void)src;
	return *this;
}

IOperand const * Parser::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const * (Parser::*f[5])(std::string const & value) const = {
		&Parser::createInt8,
		/* &Parser::createInt16, */
		/* &Parser::createInt32, */
		/* &Parser::createFloat, */
		/* &Parser::createDouble, */
	};
	return (this->*f[type])(value);
}

IOperand const * Parser::createInt8( std::string const & value ) const
{
	return new Int8(value);
}

/* IOperand const * Parser::createInt16( std::string const & value ) const{} */
/* IOperand const * Parser::createInt32( std::string const & value ) const; */
/* IOperand const * Parser::createFloat( std::string const & value ) const; */
/* IOperand const * Parser::createDouble( std::string const & value ) const; */


#define NUM "(.*)\\((.*)\\)(.*)"

IOperand const *Parser::CreateOperand(std::string str) const
{
	eOperandType type;
	std::smatch match;
	t_optype dic_type[] = {
		{.regex = "int8", .type = INT8},
		{.regex = "int16", .type = INT16},
		{.regex = "int8", .type = INT32},
		{.regex = "float", .type = FLOAT},
		{.regex = "double", .type = DOUBLE},
	};

	if (!regex_match(str, match, std::regex(NUM)))
	{
		std::cout << "regex no match";
	}
	for (t_optype elem: dic_type)
	{
		if (str.find(elem.regex))
		{
			type = elem.type;
			break;
		}
	}
	return createOperand(type, match[2].str());
}


void	setFunction(Token * token)
{
	func_tab_t funcMap =
	{
		{ "pop", &Computor::pop},
		{ "dump", &Computor::dump},
		{ "add", &Computor::add},
		{ "sub", &Computor::sub},
		{ "mul", &Computor::mul},
		{ "div", &Computor::div},
		{ "mod", &Computor::mod},
		{ "print", &Computor::print},
		/* { "exit", &Computor::exit} */
	};
	func_tab_t::iterator it = funcMap.find(token->get_str());
	if (it == funcMap.end())
	{
		if (token->get_str().find("push"))
			token->f = &Computor::push;
		if (token->get_str().find("assert"))
			token->f = &Computor::ft_assert;
	}
	token->method = funcMap.at(token->get_str());

}

void Parser::parse()
{
	for (std::shared_ptr<Token> token: _tokens)
	{
		switch (token->get_type())
		{
			case TokenType::Value:
				token->op = std::make_shared<const IOperand * >(CreateOperand(token->get_str()));

			case TokenType::Instruction:
				setFunction(token.get());
			default:
				;
				/* return ; */

		}
	}
}
