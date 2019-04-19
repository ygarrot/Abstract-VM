/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 15:29:50 by ygarrot          ###   ########.fr       */
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

void  Computor::dump()
{
	for (IOperand const * op : _vect)
	{
		std::cout << op->toString(); 
	}
}

typedef void (Computor::*op_func)();
typedef std::map<std::string, op_func> func_tab_t ;

void Computor::vm_dic()
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
	func_tab_t::iterator it = funcMap.find("smod");
	if (it == funcMap.end())
		std::cout <<"end"<<std::endl;
}
