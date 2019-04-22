/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:37:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 11:44:25 by ygarrot          ###   ########.fr       */
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
	/* std::cout << static_cast<int>(type) << std::endl; */
	IOperand const * (Parser::*f[5])(std::string const & value) const = {
		&Parser::createInt8,
		/* &Parser::createInt16, */
		/* &Parser::createInt32, */
		/* &Parser::createFloat, */
		/* &Parser::createDouble, */
	};
	(void)type;
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
	std::map<std::string, eOperandType> dic_type= {
		{"int8",  INT8},
		{"int16",  INT16},
		{"int32",  INT32},
		{"float",  FLOAT},
		{"double", DOUBLE},
	};

	if (!regex_match(str, match, std::regex(NUM)))
	{
		std::cout << "regex no match";
	}
	type = dic_type[match[1].str()];
	return createOperand(type, match[2].str());
}


void	Parser::setFunction(Token * token)
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
		{ "exit", &Computor::exit}
	};
	func_tab_t::iterator it = funcMap.find(token->get_str());
	if (it == funcMap.end())
	{
		if (!token->get_str().compare("push"))
		{
			token->f = &Computor::push;
		}
		else if (!token->get_str().compare("assert"))
			token->f = &Computor::ft_assert;
		return ;
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
				token->op = CreateOperand(token->get_str());
				break;
			case TokenType::Instruction:
				setFunction(token.get());
				break;
			default:
				;
				/* return ; */

		}
	}
}
