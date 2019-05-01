/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:55:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/01 16:15:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <iostream>
#include <string>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m" 
#define BLUE "\033[1;34m" 
#define MAGENTA "\033[1;35m" 
#define CYAN "\033[1;36m" 
#define BLACK "\033[1;30m" 
#define RESET "\033[0m" 

class TokenException : public std::exception
{
	public:
		TokenException(std::string defaul, int line);
		TokenException();
		TokenException(int line);
		TokenException(TokenException const &src);
		TokenException & operator=(TokenException const & src);
		void set_str(int line);
		virtual ~TokenException(void) throw();
		virtual const char * what(void) const throw();
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

class NoExitException : public TokenException
{
	public:
		explicit NoExitException(){_default= "no exit found";};
		NoExitException(int line) : TokenException( "no exit found", line) {};
		NoExitException(NoExitException const &src);
		NoExitException & operator=(NoExitException const & src);
		virtual ~NoExitException(void) throw() {};
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

class NoArgumentException : public TokenException
{
	public:
		explicit NoArgumentException(){_default= "instruction expected an argument";};
		NoArgumentException(int line) : TokenException( "instruction expected an argument", line) {};
		NoArgumentException(NoArgumentException const &src);
		NoArgumentException & operator=(NoArgumentException const & src);
		virtual ~NoArgumentException(void) throw() {};
};

class NotEnoughValueException : public TokenException
{
	public:
		explicit NotEnoughValueException(){_default= "The stack is composed of strictly less that two values";};
		NotEnoughValueException(int line) : TokenException( "The stack is composed of strictly less that two values", line) {};
		NotEnoughValueException(NotEnoughValueException const &src);
		NotEnoughValueException & operator=(NotEnoughValueException const & src);
		virtual ~NotEnoughValueException(void) throw() {};
};

class BitwiseOnFloatException : public TokenException
{
	public:
		explicit BitwiseOnFloatException(){_default= "Unabled to do bitwise operation between float";};
		BitwiseOnFloatException(int line) : TokenException(  "Unabled to do bitwise operation between float", line) {};
		BitwiseOnFloatException(BitwiseOnFloatException const &src);
		BitwiseOnFloatException & operator=(BitwiseOnFloatException const & src);
		virtual ~BitwiseOnFloatException(void) throw() {};
};

#endif
