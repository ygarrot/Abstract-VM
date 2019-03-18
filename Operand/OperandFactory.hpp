/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:53:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/18 13:55:33 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.h"
/* #include "IOperand.hpp" */
/* #include "Int16.hpp" */
/* #include "Int32.hpp" */
/* #include "Float.hpp" */
/* #include "Double.hpp" */
class OperandFactory
{
	public:
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};
