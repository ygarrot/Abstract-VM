/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 16:53:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

void	Computor::check_stack(size_t size)
{
	if (_stack.size() < size)
		throw NotEnoughValueException();
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
		try{
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
		catch (TokenException &e)
		{
			e.set_str(token->get_line());
			throw e;
			/* throw TokenException(token->get_line()); */
		}
	}
}

void		Computor::ft_assert(IOperand const * v)
{
	if (_stack.size() < 1)
		throw EmptyStackException();
	if(_stack.back()->toString().compare(v->toString()))
		throw AssertException();
}

void		Computor::push(IOperand const * op)
{
	_stack.push_back(std::shared_ptr< const IOperand>(op));
}

void	Computor::pop()
{
	if (_stack.size() < 1)
		throw EmptyStackException();
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
	if (_stack.back()->getType() != INT8)
		throw AssertException();
	std::cout << reinterpret_cast<TOperand<int8_t> const *>(_stack.back().get())->get_value() << std::endl;
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


