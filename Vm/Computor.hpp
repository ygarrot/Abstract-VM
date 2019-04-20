/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:52 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 15:11:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_COMPUTOR_H
#define ABSTRACT_VM_COMPUTOR_H

/* #include "../Operand/IOperand.hpp" */
#include <iostream>
#include <vector>
#include <exception>
#include "../Operand/Int8.hpp"
#include <functional>
#include <map>
#include <string>
#include <iostream>
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
		std::vector< IOperand const * > get_elem(size_t n);
		void		push(IOperand const * op);
		void		pop();
		void	dump();
		void		ft_assert(IOperand const * op);
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	print();
		void	exit();
		void	check_stack(){};
	private:
		std::vector< const IOperand *> _vect;
};

#endif


