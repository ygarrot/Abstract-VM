/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 11:46:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Int8.hpp"

Int8::Int8(std::string str) 
{
	_n = stoi(str);
	_str = std::to_string(_n);
}

Int8::~Int8() 
{

}

Int8::Int8(Int8 const &src)
{
	*this = src;
}

Int8     &Int8::operator=(Int8 const & src) 
{
	(void)src;
	return *this;
}

Int8::Int8(int type):TOperand(type){};
Int8::Int8(void):TOperand(){};
/* IOperand const * Int8::operator+( IOperand const & rhs ) const */
/* { */
	/* return new Int8(this->toString() + rhs.toString()); */
/* } */

/* virtual int getPrecision( void ) const = 0; // Precision of the type of the instance */
/* virtual eOperandType getType( void ) const = 0; // Type of the instance */
/* virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference */
/* virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product */
/* virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient */
/* virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo */
/* virtual std::string const & toString( void ) const = 0; // String representation of the instance */
/* virtual ~IOperand( void ) {} */
