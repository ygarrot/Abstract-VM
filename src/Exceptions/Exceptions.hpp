/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:55:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 16:58:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <iostream>
#include <string>

class TokenException : public std::exception
{
	public:
		TokenException(std::string defaul, int line): _default(defaul){ set_str(line);};
		TokenException(): _str(_default){};
		TokenException(int line) { set_str(line);};
		/* TokenException(TokenException const &src); */
		/* TokenException & operator=(TokenException const & src); */
		void set_str(int line) { _str = "Line : " + std::to_string(line) + " Error : " + _default; };
		virtual ~TokenException(void) throw() {};
		virtual const char * what(void) const throw() {return _str.c_str();}
	protected:
		std::string _default;
		std::string _str;
};


class UnknownInstructionException : public TokenException
{
	public:
		explicit UnknownInstructionException(){_default="Unkown Instruction"; };
		UnknownInstructionException(int line) : TokenException("Unkown Instruction", line) {};
		UnknownInstructionException(UnknownInstructionException const &src);
		UnknownInstructionException & operator=(UnknownInstructionException const & src);
		virtual ~UnknownInstructionException(void) throw(){};
};

class ValueUnderflowException : public TokenException
{
	public:
		explicit ValueUnderflowException(){_default="Value underflow";};
		ValueUnderflowException(int line) : TokenException( "Value underflow", line) {};
		ValueUnderflowException(ValueUnderflowException const &src);
		ValueUnderflowException & operator=(ValueUnderflowException const & src);
		virtual ~ValueUnderflowException(void) throw(){};
};

class ValueOverflowException : public TokenException
{
	public:
		explicit ValueOverflowException(){_default="Value overflow";};
		ValueOverflowException(int line) : TokenException( "Value overflow", line) {};
		ValueOverflowException(ValueOverflowException const &src);
		ValueOverflowException & operator=(ValueOverflowException const & src);
		virtual ~ValueOverflowException(void) throw(){};
};

class EmptyStackException : public TokenException
{
	public:
		explicit EmptyStackException(){_default= "Stack is empty";};
		EmptyStackException(int line) : TokenException( "Stack is empty", line) {};
		EmptyStackException(EmptyStackException const &src);
		EmptyStackException & operator=(EmptyStackException const & src);
		virtual ~EmptyStackException(void)throw(){};
};

class FloatingPointException : public TokenException
{
	public:
		explicit FloatingPointException(){_default= "Floating point exception";};
		FloatingPointException(int line) : TokenException( "Floating point exception", line) {};
		FloatingPointException(FloatingPointException const &src);
		FloatingPointException & operator=(FloatingPointException const & src);
		virtual ~FloatingPointException(void) throw() {};
};

class AssertException : public TokenException
{
	public:
		explicit AssertException(){_default= "Assertion Failed";};
		AssertException(int line) : TokenException( "Assertion Failed", line) {};
		AssertException(AssertException const &src);
		AssertException & operator=(AssertException const & src);
		virtual ~AssertException(void) throw() {};
};

class NotEnoughValueException : public TokenException
{
	public:
		explicit NotEnoughValueException(){_default= "Not enough Value exception";};
		NotEnoughValueException(int line) : TokenException( "Not enough Value exception", line) {};
		NotEnoughValueException(NotEnoughValueException const &src);
		NotEnoughValueException & operator=(NotEnoughValueException const & src);
		virtual ~NotEnoughValueException(void) throw() {};
};
#endif
