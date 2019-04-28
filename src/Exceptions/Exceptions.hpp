/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:55:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 13:09:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class UnkownInstructionException : public std::exception
{
	public:
		UnkownInstructionException(){};
		UnkownInstructionException(UnkownInstructionException const &src);
		UnkownInstructionException & operator=(UnkownInstructionException const & src);
		/* ~UnkownInstructionException(void){}; */
		virtual const char * what(void) const throw() ;
};

class ValueUnderflowException : public std::exception
{
	public:
		ValueUnderflowException(){};
		ValueUnderflowException(ValueUnderflowException const &src);
		ValueUnderflowException & operator=(ValueUnderflowException const & src);
		/* ~ValueUnderflowException(void){}; */
		virtual const char * what(void) const throw() ;
};

class ValueOverflowException : public std::exception
{
	public:
		ValueOverflowException(){};
		ValueOverflowException(ValueOverflowException const &src);
		ValueOverflowException & operator=(ValueOverflowException const & src);
		/* ~ValueOverflowException(void){}; */
		virtual const char * what(void) const throw() ;
};

class EmptyStackException : public std::exception
{
	public:
		EmptyStackException(){};
		EmptyStackException(EmptyStackException const &src);
		EmptyStackException & operator=(EmptyStackException const & src);
		/* ~EmptyStackException(void){}; */
		virtual const char * what(void) const throw() ;
};

class FloatingPointException : public std::exception
{
	public:
		FloatingPointException(){};
		FloatingPointException(FloatingPointException const &src);
		FloatingPointException & operator=(FloatingPointException const & src);
		/* ~FloatingPointException(void){}; */
		virtual const char * what(void) const throw() ;
};

class AssertException : public std::exception
{
	public:
		AssertException(){};
		AssertException(AssertException const &src);
		AssertException & operator=(AssertException const & src);
		/* ~AssertException(void){}; */
		virtual const char * what(void) const throw() ;
};

class NotEnoughValueException : public std::exception
{
	public:
		NotEnoughValueException(){};
		NotEnoughValueException(NotEnoughValueException const &src);
		NotEnoughValueException & operator=(NotEnoughValueException const & src);
		/* ~NotEnoughValueException(void){}; */
		virtual const char * what(void) const throw() ;
};
#endif
