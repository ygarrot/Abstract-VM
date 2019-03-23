/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:52 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/23 18:15:58 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_COMPUTOR_H
#define ABSTRACT_VM_COMPUTOR_H

/* #include "../Operand/IOperand.hpp" */
#include "../Operand/TOperand.hpp"
#include <iostream>
#include <vector>
#include <boost/variant.hpp>
#include <exception>
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
		std::vector<boost::variant<TOperand<int>>> get_elem(size_t n);
		template<typename T>
		void		push(TOperand<T> const & op);
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
		std::vector<boost::variant<TOperand<int>>> _vect;
};

#endif
