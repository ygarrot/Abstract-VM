/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 13:17:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_H
#define INT8_H

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Int8: public TOperand<int>
{
	public:
		virtual eOperandType getType( void ) const { return INT8;}; // Type of the instance
		/* eOperandType getType( void ){}; // Type of the instance */
		/* virtual void check_exceptions(IOperand const & rhs); */
		/* virtual void check_underflow(IOperand const & rhs); */
		/* virtual void check_overflow(IOperand const & rhs); */
		Int8(void):TOperand(){};
		Int8(std::string){};
		Int8(int type):TOperand(type){};
		Int8(Int8 const & src){(void)src;};
		IOperand &operator=(IOperand const & src){(void)src; return *this;};
		/* TOperand &operator=(TOperand const & src){(void)src; return *this;}; */
		~Int8(void){};
	private:
};


#endif
