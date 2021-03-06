/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:48:24 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 13:25:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>

typedef enum  eOperandType
{
	INT8 = 0,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
} tOperandType;

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0; // Type of the instance
		virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo

		virtual IOperand const * operator|( IOperand const & rhs ) const = 0; // Modulo
		virtual IOperand const * operator&( IOperand const & rhs ) const = 0; // Modulo
		virtual IOperand const * operator^( IOperand const & rhs ) const = 0; // Modulo

		virtual std::string const & toString( void ) const = 0; // String representation of the instance
		virtual ~IOperand( void ) {};
};

#endif
