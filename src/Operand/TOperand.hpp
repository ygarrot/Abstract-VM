/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 17:45:16 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_TOPERAND_HPP
#define ABSTRACT_VM_TOPERAND_HPP

class OperandFactory;
template<typename T>
class TOperand;

#include <cfenv>
#include <iostream>
#include <cmath>
#include <cstdint>

#include "IOperand.hpp"

enum eFunctionType
{
	ADD,
	SUB,
	MULT,
	DIV,
	MOD,
};

class OperandFactory
{
	public:
		IOperand const * createOperand(std::string str) const;
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private:
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
};
static const OperandFactory OpFactory;

#include "OperandFactory.hpp"
#include "../Exceptions/Exceptions.hpp"

template<typename T>
class TOperand: public IOperand {
	public:
		IOperand &operator=(IOperand const & src);
		TOperand(){};
		TOperand(std::string str, T value, eOperandType type) : _str(str), _n(value), _type(type){};
		TOperand(TOperand const & src){(void)src;};
		~TOperand(void){};
		T		get_value(void) const {return this->_n;};
		virtual	int getPrecision( void ) const;
		virtual	eOperandType getType( void ) const;

		template<typename B>
			void	check_exceptions(B a, B b,
					void (TOperand<T>::*f)( B a, B b) const) const;

		template<typename B>
			void checkAddOverflow(B a, B b) const;
		template<typename B>
			void checkMulOverflow(B a, B b) const;
		template<typename B>
			void checkSubOverflow(B a, B b) const;
		template<typename B>
			void checkModOverflow(B a, B b) const;
		template<typename B>
			void checkDivOverflow(B a, B b) const;

		auto get_highest_prec(TOperand<T> const & rhs) const;
		template<typename B>
			std::pair<B, B> get_type(IOperand const & op) const;

		template<typename B>
			IOperand const * CreateOperand(eOperandType type, B value) const;
		template<typename B>
		IOperand const * apply_func(eOperandType operandType, eFunctionType functionType, B a, B b) const;
		IOperand const * choose_type( IOperand const & rhs, eFunctionType functionType) const;

		virtual	IOperand const * operator+( IOperand const & rhs ) const;
		virtual	IOperand const * operator-( IOperand const & rhs ) const;
		virtual	IOperand const * operator*( IOperand const & rhs ) const;
		virtual	IOperand const * operator/( IOperand const & rhs ) const;
		virtual	IOperand const * operator%( IOperand const & rhs ) const;
		virtual	std::string const & toString( void ) const;
		std::string _str;
		T _n;
		eOperandType _type;
	protected:
};


template<typename T>
template<typename B>
std::pair<B, B> TOperand<T>::get_type(IOperand const & op) const
{
	if (op.getType() == INT8)
		return std::make_pair(static_cast<B>(this->_n), static_cast<B>(stoi(op.toString())));
	if (op.getType() == INT16)
		return std::make_pair(static_cast<B>(this->_n), static_cast<B>(stoi(op.toString())));
	if (op.getType() == INT32)
		return std::make_pair(static_cast<B>(this->_n), static_cast<B>(stoi(op.toString())));
	if (op.getType() == FLOAT)
		return std::make_pair(static_cast<B>(this->_n), static_cast<B>(stof(op.toString())));
	return std::make_pair(static_cast<B>(this->_n), static_cast<B>(stod(op.toString())));
}


template<typename T>
template<typename B>
IOperand const * TOperand<T>::CreateOperand(eOperandType type, B value) const
{
	return OpFactory.createOperand(type, std::to_string(value));
}

	template<typename T>
IOperand &TOperand<T>::operator=(IOperand const & src)
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(src);
	if (tmp == this)
		return *this;
	_n = tmp._n;
	_type = tmp._type;
}

template<typename T>
int TOperand<T>::getPrecision( void ) const
{
	return (static_cast<int>(this->_type));
}

template<typename T>
std::string const & TOperand<T>::toString( void ) const
{
	return _str;
}

template<typename T>
eOperandType TOperand<T>::getType( void ) const
{
	return (this->_type);
}

	template<typename T>
void subOvf(T a, T b) 
{ 
	std::feclearexcept(FE_ALL_EXCEPT);
	std::fetestexcept(FE_OVERFLOW);
	std::fetestexcept(FE_UNDERFLOW);
	(void)a;(void)b;
	std::cout << std::exp(a + b) << std::endl;
	if (std::fetestexcept(FE_OVERFLOW))
		std::cout << "overflow";
	if (std::fetestexcept(FE_UNDERFLOW))
		std::cout << "underflow";
}

template<typename T>
template<typename B>
void TOperand<T>::checkDivOverflow(B a, B b) const
{ 
	if ( (b == 0.0 || ( (a == std::numeric_limits<B>::max()) && (b == -1.0) ) ))
	{
		throw FloatingPointException(); 
	}
}

template<typename T>
template<typename B>
void TOperand<T>::checkModOverflow(B a, B b) const
{ 
	if ( (b == 0.0 || ( (a == std::numeric_limits<B>::max()) && (b == -1.0) ) ))
	{
		throw FloatingPointException(); 
	}
}

template<typename T>
template<typename B>
void TOperand<T>::checkMulOverflow(B a, B b) const
{ 
	if (a > std::numeric_limits<B>::max() / b)
	{
		throw ValueOverflowException(); 
	}
	if ((a < std::numeric_limits<B>::min() / b))
	{
		throw ValueUnderflowException(); 
	}
}

template<typename T>
template<typename B>
void TOperand<T>::checkSubOverflow(B a, B b) const
{ 
	if ((a < 0.0) != (b < 0.0)
			&& std::abs(b) > std::numeric_limits<B>::min() + std::abs(a))
   	{
		a < 0.0 ? throw ValueUnderflowException() : throw ValueOverflowException();
	}
} 

template<typename T>
template<typename B>
void TOperand<T>::checkAddOverflow(B a, B b) const
{ 
	if ((a < 0.0) == (b < 0.0)
			&& std::abs(b) > std::numeric_limits<B>::max() - std::abs(a)) {
		a < 0.0 ? throw ValueUnderflowException() : throw ValueOverflowException();
	}
} 

template<typename T>
template<typename B>
void	TOperand<T>::check_exceptions(B a, B b,
		void (TOperand<T>::*meth) (B a, B b)const) const
{
	if (!std::isnormal(b) || !std::isnormal(b))
		;
	(this->*meth)(a, b);
}

	template<typename T>
std::ostream & operator<<(std::ostream & o, TOperand<T> const & rhs)
{
	o << rhs.get_value(); 
	return o;
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::apply_func(eOperandType operandType, eFunctionType functionType, B a, B b) const
{
	switch (functionType)
	{
		case ADD:
			check_exceptions(a, b, &TOperand<T>::checkAddOverflow<B>);
			return CreateOperand<B>(operandType, a + b);
		case SUB:
			check_exceptions(a, b, &TOperand<T>::checkSubOverflow<B>);
			return CreateOperand<B>(operandType, a - b);
		case MULT:
			check_exceptions(a, b, &TOperand<T>::checkMulOverflow<B>);
			return CreateOperand<B>(operandType, a + b);
		case DIV:
			check_exceptions(a, b, &TOperand<T>::checkDivOverflow<B>);
			return CreateOperand<B>(operandType, a * b);
		case MOD:
			check_exceptions(a, b, &TOperand<T>::checkModOverflow<B>);
			return CreateOperand<B>(operandType, fmod(a , b));
	}
}

template<typename T>
IOperand const * TOperand<T>::choose_type( IOperand const & rhs, eFunctionType functionType) const
{
	if (this->getType()  == DOUBLE || rhs.getType() == DOUBLE)
	{
		auto[a, b] = get_type<double>(rhs);
		return apply_func<double>(DOUBLE, functionType, a , b);
	}
	if (this->getType()  == FLOAT || rhs.getType() == FLOAT)
	{
		auto[a, b] = get_type<float>(rhs);
		return apply_func<float>(FLOAT, functionType, a , b);
	}
	if (this->getType()  == INT32 || rhs.getType() == INT32)
	{
		auto[a, b] = get_type<int32_t>(rhs);
		return apply_func<int32_t>(INT32, functionType, a , b);
	}
	if (this->getType()  == INT16 || rhs.getType() == INT16)
	{
		auto[a, b] = get_type<int16_t>(rhs);
		return apply_func<int16_t>(INT8, functionType, a , b);
	}
	auto[a, b] = get_type<int8_t>(rhs);
	return apply_func<int8_t>(INT8, functionType, a , b);
}

template<typename T>
IOperand const * TOperand<T>::operator-( IOperand const & rhs ) const
{
	return choose_type(rhs, SUB);
}

template<typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	return choose_type(rhs, ADD);
}

template<typename T>
IOperand const * TOperand<T>::operator*( IOperand const & rhs ) const
{
	return choose_type(rhs, MULT);
}


template<typename T>
IOperand const * TOperand<T>::operator/( IOperand const & rhs ) const
{
	return choose_type(rhs, DIV);
}


template<typename T>
IOperand const * TOperand<T>::operator%( IOperand const & rhs ) const
{
	return choose_type(rhs, MOD);
}

#endif
