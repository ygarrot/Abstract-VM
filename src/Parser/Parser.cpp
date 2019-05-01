/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:37:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/01 14:56:41 by ygarrot          ###   ########.fr       */
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
	t_verbose verboseDic[] =
	{
		{ "pop", "", &Computor::pop, 0, 0},
		{ "dump","", &Computor::dump, 0, 0},
		{ "add", "+", &Computor::add, 0, 2},
		{ "sub", "-", &Computor::sub, 0, 2},
		{ "mul", "*", &Computor::mul, 0, 2},
		{ "div", "/", &Computor::div, 0, 2},
		{ "mod", "%", &Computor::mod, 0, 2},
		{ "or", "|", &Computor::ft_or, 0, 2},
		{ "and", "&", &Computor::ft_and, 0, 2},
		{ "xor", "^", &Computor::ft_xor, 0, 2},
		/* { "min", "<", &Computor::min, 0}, */
		/* { "max", &Computor::max, 0}, */
		{ "print", "", &Computor::print, 0, 0},
		{ "exit", "", &Computor::exit, 0, 0},
		{ "push", "", 0, &Computor::push, 1},
		{ "assert", "", 0, &Computor::ft_assert, 1},
	};

	func_tab_t funcMap =
	{
		{ "pop", &verboseDic[0]},
		{ "dump", &verboseDic[1]},
		{ "add", &verboseDic[2]},
		{ "sub", &verboseDic[3]},
		{ "mul", &verboseDic[4]},
		{ "div", &verboseDic[5]},
		{ "mod", &verboseDic[6]},
		{ "or", &verboseDic[7]},
		{ "and", &verboseDic[8]},
		{ "xor", &verboseDic[9]},
		/* { "min", &Computor::min}, */
		/* { "max", &Computor::max}, */
		{ "print", &verboseDic[10]},
		{ "exit", &verboseDic[11]},
		{ "push", &verboseDic[12]},
		{ "assert", &verboseDic[13]}
	};
	value_expected = !token->get_str().compare("push") && !token->get_str().compare("assert");
	token->verbose = *funcMap.at(token->get_str());
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
					value_expected = false;
					token->op = OpFactory.createOperand(token->get_str());
					break;
				case TokenType::Instruction:
					if (value_expected)
					{
						throw NoArgumentException();
					}
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
