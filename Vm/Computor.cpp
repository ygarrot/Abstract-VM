/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:20 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/23 18:29:00 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Computor.hpp"

template<typename T>
class my_visitor : public boost::static_visitor<T>
{
	public:
		int operator()(TOperand & op, TOperand &op2) const
		{
			return op
		}
};


std::vector<boost::variant<TOperand<int>>> Computor::get_elem(size_t n)
{
	if (_vect.size() < n)
		;/* throw std::exception("empty stack"); */
	return std::vector<boost::variant<TOperand<int>>>(_vect.end() - n, _vect.end());
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
	std::vector<boost::variant<TOperand<int>>> tmp = get_elem(2);
	
	boost::apply_visitor
	double tmp = tmp[1]._n + tmp[2]._n;
}
