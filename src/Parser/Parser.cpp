/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:37:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 13:47:36 by ygarrot          ###   ########.fr       */
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

TOKEN_PTR Parser::get_tokens()
{
	return _tokens;
}

void Parser::set_tokens(TOKEN_PTR tokens)
{
	_tokens = tokens;
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

void	Parser::setFunction(Token * token, bool & value_expected)
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
		{ "or", &Computor::ft_or},
		{ "and", &Computor::ft_and},
		{ "xor", &Computor::ft_xor},
		{ "print", &Computor::print},
		{ "exit", &Computor::exit}
	};
	func_tab_t::iterator it = funcMap.find(token->get_str());
	if (it == funcMap.end())
	{
		value_expected = true;
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

int Parser::parse()
{
	int ret = 1;
	bool value_expected = false;

	for (std::shared_ptr<Token> token: _tokens)
	{
		try{
			switch (token->get_type())
			{
				case TokenType::Value:
					token->op = OpFactory.createOperand(token->get_str());
					value_expected = false;
					break;
				case TokenType::Instruction:
					if (value_expected)
						throw UnknownInstructionException();
					setFunction(token.get(), value_expected);
					break;
				default:
					;
			}
		}
		catch (TokenException &e)
		{
			e.set_str(token->get_line());
			std::cout << e.what() << "\n";
			ret = -1;
		}
	}
	return ret;
}
