/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 16:18:01 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

void	Computor::check_stack(size_t size)
{
	if (_stack.size() < size)
		throw EmptyStackException();
}

OP_PTR Computor::get_elem(size_t n)
{
	check_stack(n);
	OP_PTR ret(_stack.end() - n, _stack.end());
	while (n--)
	{
		_stack.pop_back();
	}
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
					/* std::cout << token->get_str() << std::endl; */
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

void		Computor::ft_assert(IOperand const * v)
{
	OP_PTR op = get_elem(1);
	assert(op[0]->toString().compare(v->toString()));
}

void		Computor::push(IOperand const * op)
{
	/* check_stack(); */
	_stack.push_back(std::shared_ptr< const IOperand>(op));
}

void	Computor::pop()
{
	check_stack(1);
	_stack.pop_back();
}

void  Computor::add()
{
	OP_PTR op = get_elem(2);
	push(*op[0] + *op[1]);
}

void  Computor::sub()
{
	OP_PTR op = get_elem(2);
	push(*op[0] - *op[1]);
}

void  Computor::mul()
{
	OP_PTR op = get_elem(2);
	push(*op[0] * *op[1]);
}

void  Computor::div()
{
	OP_PTR op = get_elem(2);
	push(*op[0] / *op[1]);
}

void  Computor::mod()
{
	OP_PTR op = get_elem(2);
	push(*op[0] % *op[1]);
}

void  Computor::print()
{
	OP_PTR op = get_elem(1);
	/* std::cout << static_cast<char>(op[0]->toString()); */
}

void	Computor::exit()
{
}

void  Computor::dump()
{
	/* std::cout << "dump\n"; */
	for (OP_PTR::iterator it = _stack.begin(); it != _stack.end(); ++it)
	{
		std::cout << it->get()->toString() << "\n"; 
	}
}


