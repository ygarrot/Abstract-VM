/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:31:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/26 10:13:00 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const * (OperandFactory::*f[5])(std::string const & value) const = {
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble,
	};
	return (this->*f[type])(value);
}


IOperand const *OperandFactory::CreateOperand(std::string str) const
{
	eOperandType type;
	std::smatch match;
	std::map<std::string, eOperandType> dic_type= {
		{"int8",  INT8},
		{"int16",  INT16},
		{"int32",  INT32},
		{"float",  FLOAT},
		{"double", DOUBLE},
	};

	if (!regex_match(str, match, std::regex(NUM)))
	{
		std::cout << "regex no match";
	}
	type = dic_type[match[1].str()];
	return createOperand(type, match[2].str());
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	return new TOperand<int8_t>(value, stoi(value), INT8);
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	return new TOperand<int8_t>(value, stoi(value), INT16);
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	return new TOperand<int8_t>(value, stoi(value), INT32);
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	return new TOperand<int8_t>(value, stof(value), FLOAT);
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	return new TOperand<double>(value, stod(value), DOUBLE);
}


