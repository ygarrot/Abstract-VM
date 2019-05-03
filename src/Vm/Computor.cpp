/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/02 10:46:34 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

Computor &Computor::operator=(Computor const & src)
{
	_verbose = src._verbose;
	_stack = src._stack;
	_tokens = src._tokens;
	return *this;
};

Computor::Computor(Computor const & src)
{
	_verbose = src._verbose;
	_stack = src._stack;
	_tokens = src._tokens;
}

TOKEN_PTR Computor::get_tokens()
{
	return _tokens;
};

void Computor::set_tokens(TOKEN_PTR tokens)
{
	_tokens = tokens;
};

void	Computor::displayFuncName(Token *token)
{
	std::cout
		<< BLACK
		<< "Line " << token->get_line() << " : "
		<< CYAN
		<< token->verbose.func_name;
}

void	Computor::verboseOneArg(IOperand const& op)
{
	std::cout
		<<  " : "
		<< BLUE 
		<< op.toString();
}

void	Computor::verboseTwoArg(Token *token, OP_PTR op)
{
	verboseOneArg(*op[0]);
	std::cout
		<< " "
		<< token->verbose.op << " "
		<< (*op[1]).toString() << " = "
		<< _stack.back()->toString();
}

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
	OP_PTR ret; 

	for (TOKEN_PTR::iterator it = _tokens.begin(); it != _tokens.end(); ++it)
	{
		Token *token = it->get();
		try
		{
			switch (token->get_type())
			{
				case TokenType::Instruction:
					if (it + 1 != _tokens.end() && (it + 1)->get()->get_type() != TokenType::Instruction)
					{
						++it;
						if (_verbose) displayFuncName(token);
						if (_verbose) verboseOneArg(*it->get()->op);
						token->verbose.f(this, it->get()->op);
						if (_verbose) std::cout << "\n";
					}
					else
					{
						if (_verbose && token->verbose.arg_number == 2 && _stack.size() >= 2)
							ret = OP_PTR(_stack.end() - 2, _stack.end());
						token->verbose.method(this);
						if (_verbose) displayFuncName(token);
						if (_verbose && token->verbose.arg_number == 2 )
							verboseTwoArg(token, ret);
						if (_verbose) std::cout << "\n";
					}
					break;
				default:
					;
			}
		}
		catch (TokenException &e)
		{
			e.set_str(token->get_line());
			throw e;
		}
	}
	if (_tokens.empty() || _tokens.back()->get_str().compare("exit"))
		throw NoExitException(_tokens.empty() ? 1 : _tokens.back()->get_line()); 
}

void		Computor::ft_assert(IOperand const * v)
{
	std::shared_ptr<IOperand const > t(v);
	(void)v;
	if (_stack.size() < 1)
		throw EmptyStackException();
	if (v->getType() != _stack.back()->getType())
		throw AssertException();
	if (_stack.back()->toString().compare(v->toString()))
		throw AssertException();
}

void		Computor::max()
{
	if (_stack.size() < 1)
		throw EmptyStackException();
	std::cout << std::max_element(_stack.begin(), _stack.end())->get()->toString() << std::endl;
}


void		Computor::min()
{
	if (_stack.size() < 1)
		throw EmptyStackException();
	std::cout << std::min_element(_stack.begin(), _stack.end())->get()->toString() << std::endl;
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

void  Computor::ft_or()
{
	OP_PTR op = get_elem(2);
	push(*op[0] | *op[1]);
}

void  Computor::ft_and()
{
	OP_PTR op = get_elem(2);
	push(*op[0] | *op[1]);
}

void  Computor::ft_xor()
{
	OP_PTR op = get_elem(2);
	push(*op[0] | *op[1]);
}

void  Computor::print()
{
	if (_stack.back()->getType() != INT8)
		throw AssertException();
	std::cout << YELLOW;
	std::cout << reinterpret_cast<TOperand<int8_t> const *>(_stack.back().get())->get_value() << std::endl;
	std::cout << RESET;
}

void	Computor::exit()
{
}

void  Computor::dump()
{
	std::cout << GREEN;
	for (OP_PTR::reverse_iterator it = _stack.rbegin(); it != _stack.rend(); ++it)
	{
		std::cout << it->get()->toString() << "\n"; 
	}
	std::cout << RESET;
}

