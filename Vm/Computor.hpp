/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:52 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 13:40:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_COMPUTOR_H
#define ABSTRACT_VM_COMPUTOR_H

/* #include "../Operand/IOperand.hpp" */
#include <iostream>
#include <vector>
#include <exception>
#include "visitor_structs.hpp"
/* typedef boost::variant<TOperand<int>> OPVARIANT; */
/* class TOperand; */
/* class IOperand; */

class Computor
{
	public:
		Computor &operator=(Computor const & src);
		Computor(){};
		Computor(std::string){};
		Computor(Computor const & src){(void)src;};
		~Computor(void){};
		std::vector< IOperand* > get_elem(size_t n);
		void		push(IOperand  * op);
		template<typename T>
		void		ft_assert(TOperand<T> const & op);
		void		pop();
		void	dump();
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	print();
		void	exit();
		void	check_stack(){};
	private:
		std::vector< IOperand *> _vect;
};

#endif

void		Computor::push(IOperand  * op)
{
	check_stack();
	_vect.push_back(op);
}


