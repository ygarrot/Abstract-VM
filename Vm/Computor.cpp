/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/24 13:27:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

std::vector<OPVARIANT> Computor::get_elem(size_t n)
{
	if (_vect.size() < n)
		;/* throw std::exception("empty stack"); */
	return std::vector<OPVARIANT>(_vect.end() - n, _vect.end());
}

		template<typename T>
void		Computor::push(TOperand<T> const & op)
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
	std::vector<OPVARIANT> tmp = get_elem(2);

	boost::apply_visitor(add_visitor(), tmp[0], tmp[1]);
}


void  Computor::dump()
{
	for (const auto& nextVariant : _vect)
	{
		boost::apply_visitor(print_visitor{}, nextVariant);
	}
}

