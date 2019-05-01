/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/01 13:47:48 by ygarrot          ###   ########.fr       */
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
	OR,
	AND,
	XOR,
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
		template<typename B>
			void checkBitwise(B a, B b) const;

		template<typename B>
			std::pair<B, B> get_type(IOperand const & op) const;

		template<typename B>
			IOperand const * CreateOperand(eOperandType type, B value) const;
		template<typename B>
			IOperand const * apply_func(eOperandType operandType, eFunctionType functionType, B a, B b) const;
		IOperand const * choose_type( IOperand const & rhs, eFunctionType functionType) const;

		IOperand const * to_double( IOperand const & rhs, eFunctionType functionType, eOperandType type) const;
		IOperand const * to_float( IOperand const & rhs, eFunctionType functionType, eOperandType type) const;
		IOperand const * to_int8_t( IOperand const & rhs, eFunctionType functionType, eOperandType type) const;
		IOperand const * to_int16_t( IOperand const & rhs, eFunctionType functionType, eOperandType type) const;
		IOperand const * to_int32_t( IOperand const & rhs, eFunctionType functionTyp, eOperandType typee) const;
		template<typename B>
			IOperand const * to_other( IOperand const & rhs, eFunctionType functionType, eOperandType type) const;

		template<typename B>
			IOperand const * add( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * sub( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * div( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * mod( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * mul( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * ft_or( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * ft_and( B a, B b, eOperandType operandType) const;
		template<typename B>
			IOperand const * ft_xor( B a, B b, eOperandType operandType) const;

		virtual	IOperand const * operator+( IOperand const & rhs ) const;
		virtual	IOperand const * operator-( IOperand const & rhs ) const;
		virtual	IOperand const * operator*( IOperand const & rhs ) const;
		virtual	IOperand const * operator/( IOperand const & rhs ) const;
		virtual	IOperand const * operator%( IOperand const & rhs ) const;

		virtual	IOperand const * operator|( IOperand const & rhs ) const;
		virtual	IOperand const * operator&( IOperand const & rhs ) const;
		virtual	IOperand const * operator^( IOperand const & rhs ) const;

		virtual	std::string const & toString( void ) const;
	protected:
		std::string _str;
		T _n;
		eOperandType _type;
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
			&& std::abs(b) > std::numeric_limits<B>::max() - std::abs(a))
	{
		a < 0.0 ? throw ValueUnderflowException() : throw ValueOverflowException();
	}
} 

template<typename T>
template<typename B>
void TOperand<T>::checkBitwise(B a, B b) const
{ 
	(void)a;
	(void)b;
	if (typeid(B) == typeid(float))
		throw BitwiseOnFloatException();
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
	typedef struct opFunc
	{
		char op;
		IOperand const * (TOperand::*apply)(B a, B b, eOperandType t) const;
		void (TOperand<T>::*check)(B a, B b) const;
		opFunc(char c, IOperand const * (TOperand::*app)(B a, B b, eOperandType t) const, void (TOperand<T>::*ch)(B a, B b) const) : op(c), apply(app), check(ch){};
	}t_func;
	std::map <eFunctionType, t_func*> fmap ;
	t_func operandDic[] =
	{
		{'+', &TOperand<T>::add, &TOperand<T>::checkAddOverflow<B>},
		{'-', &TOperand<T>::sub, &TOperand<T>::checkSubOverflow<B>},
		{'*', &TOperand<T>::mul, &TOperand<T>::checkMulOverflow<B>},
		{'/', &TOperand<T>::div, &TOperand<T>::checkDivOverflow<B>},
		{'%', &TOperand<T>::mod, &TOperand<T>::checkModOverflow<B>},
		{'&', &TOperand<T>::ft_and, &TOperand<T>::checkBitwise<B>},
		{'|', &TOperand<T>::ft_or, &TOperand<T>::checkBitwise<B>},
		{'^', &TOperand<T>::ft_xor, &TOperand<T>::checkBitwise<B>},
	};
	fmap.insert(std::make_pair(ADD, &operandDic[0]));
	fmap.insert(std::make_pair(SUB, &operandDic[1]));
	fmap.insert(std::make_pair(MULT, &operandDic[2]));
	fmap.insert(std::make_pair(DIV, &operandDic[3]));
	fmap.insert(std::make_pair(MOD, &operandDic[4]));
	fmap.insert(std::make_pair(AND, &operandDic[5]));
	fmap.insert(std::make_pair(OR, &operandDic[6]));
	fmap.insert(std::make_pair(XOR, &operandDic[7]));

	t_func choice = *fmap.at(functionType);
	return (this->*choice.apply)(a, b, operandType);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::to_other( IOperand const & rhs, eFunctionType functionType, eOperandType type) const
{
	std::pair<B, B> pair = get_type<B>(rhs);
	return apply_func<B>(type, functionType, pair.first, pair.second);
}

template<typename T>
IOperand const * TOperand<T>::choose_type( IOperand const & rhs, eFunctionType functionType) const
{
#define opMeth IOperand const * (TOperand::*)(IOperand const &rhs, eFunctionType ftype, eOperandType t) const
	std::map <eOperandType, opMeth> fmap =
	{
		{INT8, &TOperand::to_other<int8_t>},
		{INT16, &TOperand::to_other<int16_t>},
		{INT32, &TOperand::to_other<int32_t>},
		{FLOAT, &TOperand::to_other<float>},
		{DOUBLE, &TOperand::to_other<double>},
	};
	eOperandType highestprec = rhs.getType() > this->getType() ? rhs.getType() : this->getType();
	return (this->*fmap[highestprec])(rhs,functionType, highestprec);
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
IOperand const * TOperand<T>::operator|( IOperand const & rhs ) const
{
	return choose_type(rhs, OR);
}

template<typename T>
IOperand const * TOperand<T>::operator&( IOperand const & rhs ) const
{
	return choose_type(rhs, AND);
}

template<typename T>
IOperand const * TOperand<T>::operator^( IOperand const & rhs ) const
{
	return choose_type(rhs, XOR);
}

template<typename T>
IOperand const * TOperand<T>::operator%( IOperand const & rhs ) const
{
	return choose_type(rhs, MOD);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::sub( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, a - b);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::add( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, a + b);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::mul( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, a * b);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::div( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, a / b);
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::mod( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, fmod(a, b));
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::ft_and( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, static_cast<int>(a) & static_cast<int>(b));
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::ft_or( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, static_cast<int>(a) | static_cast<int>(b));
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::ft_xor( B a, B b, eOperandType operandType) const
{
	return CreateOperand<B>(operandType, static_cast<int>(a) ^ static_cast<int>(b));
}


#endif
