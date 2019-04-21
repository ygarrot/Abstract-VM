/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/21 13:06:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

std::vector< IOperand const * > Computor::get_elem(size_t n)
{
	if (_vect.size() < n)
		;/* throw std::exception("empty stack"); */
	std::vector< IOperand const * > ret(_vect.end() - n, _vect.end());
	_vect.pop_back();
	_vect.pop_back();
	return ret;
}

void		Computor::visit()
{
	for (TOKEN_PTR::iterator it = _tokens.begin(); it != _tokens.end(); ++it)
	{
		Token *token = it->get();
		switch (token->get_type())
		{
			case TokenType::Instruction:
				if (it + 1 != _tokens.end() && (it + 1)->get()->get_type() != TokenType::Instruction)
				{
					++it;
					token->f(this, it->get()->op);
				}
				else
					token->method(this);
				break;
			default:
				;
		}
	}
}

void		Computor::ft_assert(IOperand const * op)
{
	check_stack();
	_vect.push_back(op);
}

void		Computor::push(IOperand const * op)
{
	check_stack();
	_vect.push_back(op);
}

void	Computor::pop()
{
	check_stack();
	_vect.pop_back();
}

void  Computor::add()
{
	std::vector< IOperand const * > tmp = get_elem(2);
	push(*tmp[0] + *tmp[1]);
}

void  Computor::sub()
{
	std::vector< IOperand const * > tmp = get_elem(2);
	push(*tmp[0] - *tmp[1]);
}

void  Computor::mul()
{
	std::vector< IOperand const * > tmp = get_elem(2);
	push(*tmp[0] * *tmp[1]);
}

void  Computor::div()
{
	std::vector< IOperand const * > tmp = get_elem(2);
	push(*tmp[0] / *tmp[1]);
}

void  Computor::mod()
{
	std::vector< IOperand const * > tmp = get_elem(2);
	push(*tmp[0] % *tmp[1]);
}

void  Computor::print()
{
	std::vector< IOperand const * > tmp = get_elem(1);
	/* std::cout << static_cast<char>(tmp[0]->toString()); */
}

void	Computor::exit()
{
}

void  Computor::dump()
{
	for (IOperand const * op : _vect)
	{
		std::cout << op->toString(); 
	}
}


