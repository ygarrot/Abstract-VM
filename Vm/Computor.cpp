/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 13:41:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

std::vector< IOperand* > Computor::get_elem(size_t n)
{
	if (_vect.size() < n)
		;/* throw std::exception("empty stack"); */
	return std::vector< IOperand* >(_vect.end() - n, _vect.end());
}

/* void		Computor::push(TOperan const & op) */
/* { */
/* 	check_stack(); */
/* 	_vect.push_back(op); */
/* } */

void	Computor::pop()
{
	check_stack();
	_vect.pop_back();
}

void  Computor::add()
{
	TOperand <int>t;
	std::vector< IOperand* > tmp = get_elem(2);
	std::cout << *tmp[0] + *tmp[1];
	/* push<int>(t); */
}


void  Computor::dump()
{
	/* std::vector<OPVARIANT>:: it = _vect.begin(); */
	/* for (OPVARIANT & obj: _vect) { */
		/* boost::apply_visitor(print_visitor(), obj); */
	/* } */
}

