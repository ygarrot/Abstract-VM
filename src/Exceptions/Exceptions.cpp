/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:12:24 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/22 15:11:01 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char *UnkownInstructionException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *ValueOverflowException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *ValueUnderflowException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *EmpyStackException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *FloatingPointException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *AssertException::what(void) const throw()
{
	return ("Unkown Instruction");
}

const char *NotEnoughValueException::what(void) const throw()
{
	return ("Unkown Instruction");
}
