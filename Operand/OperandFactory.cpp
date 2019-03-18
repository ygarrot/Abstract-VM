/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:53:59 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/18 13:55:28 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const * (OperandFactory::*f[4])(std::string const & value) const = {
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble,
	};
	return (this->*f[type])(value);
}

/* IOperand const * OperandFactory::createInt8( std::string const & value ) const */
/* { */
/* 	/1* return new Int8(value); *1/ */
/* 	/1* return NULL; *1/ */
/* } */

/* IOperand const * OperandFactory::createInt16( std::string const & value ) const; */
/* IOperand const * OperandFactory::createInt32( std::string const & value ) const; */
/* IOperand const * OperandFactory::createFloat( std::string const & value ) const; */
/* IOperand const * OperandFactory::createDouble( std::string const & value ) const; */


