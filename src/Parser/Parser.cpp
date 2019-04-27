/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:37:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/26 12:22:38 by ygarrot          ###   ########.fr       */
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
				token->op = OpFactory.createOperand(token->get_str());
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
