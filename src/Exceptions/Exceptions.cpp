/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:12:24 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 14:22:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
#include <exception>
const char *UnkownInstructionException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *ValueOverflowException::what(void) const throw()
{
	return ("Value overflow");
}

const char *ValueUnderflowException::what(void) const throw()
{
	return ("Value undeflow");
}

const char *EmptyStackException::what(void) const throw()
{
	return ("Stack is empty");
}

const char *FloatingPointException::what(void) const throw()
{
	return ("Floating point exception");
}

const char *AssertException::what(void) const throw()
{
	return ("Assert Exception");
}

const char *NotEnoughValueException::what(void) const throw()
{
	return ("Not enough Value exception");
}
