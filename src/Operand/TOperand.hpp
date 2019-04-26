/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/26 10:22:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_TOPERAND_HPP
#define ABSTRACT_VM_TOPERAND_HPP

#include <cfenv>
#include <iostream>
#include <cmath>
#include <cstdint>

/* #include "OperandFactory.hpp" */
#include "../Exceptions/Exceptions.hpp"
#include "IOperand.hpp"

template<typename T>
class TOperand: public IOperand {
	public:
		IOperand &operator=(IOperand const & src);
		TOperand(){};
		TOperand(std::string){};
		TOperand(std::string str, T value, eOperandType type) : _str(str), _n(value), _type(type){};
		TOperand(T type){this->_n = type; this->_str = std::to_string(this->_n); };
		TOperand(TOperand const & src){(void)src;};
		~TOperand(void){};
		T		get_value(void) const {/*std::cout <<this->_n ;*/return this->_n;};
		virtual	int getPrecision( void ) const;
		virtual	eOperandType getType( void ) const;

		template<typename B>
		std::pair<B, B>	check_exceptions(TOperand const & rhs,
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
		/* auto get_highest_class(TOperand<T> const & rhs) const; */

		template<typename B>
		IOperand const * CreateOperand(B value) const;

		virtual	IOperand const * operator+( IOperand const & rhs ) const;
		virtual	IOperand const * operator-( IOperand const & rhs ) const;
		virtual	IOperand const * operator*( IOperand const & rhs ) const;
		virtual	IOperand const * operator/( IOperand const & rhs ) const;
		virtual	IOperand const * operator%( IOperand const & rhs ) const;
		virtual	std::string const & toString( void ) const;
	protected:
		/* C _base_class; */
		std::string _str;
		T _n;
		eOperandType _type;
		std::string _customType;
};

	template<typename T>
auto TOperand<T>::get_highest_prec(TOperand<T> const & rhs) const
{
	std::cout << typeid(this).name() << "\n";
	return (rhs._type > this->_type) ? rhs._n : this->_n ; 
};

/* template<typename T> */
/* auto TOperand<T>::get_highest_class(IOperand const & rhs) const */
/* { */
/* 	return (reinterpret_cast< const TOperand<T> & >(rhs)._type > this->_type) ? rhs : this ; */ 
/* }; */

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
	return (this->_n);
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
int subOvf(T a, T b) 
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
	return 1;
} 

template<typename T>
template<typename B>
void TOperand<T>::checkDivOverflow(B a, B b) const
{ 
	if ( (b == 0.0 || ( (a == std::numeric_limits<B>::max()) && (b == -1) ) ))
	{
		throw FloatingPointException(); 
	}
}

template<typename T>
template<typename B>
void TOperand<T>::checkModOverflow(B a, B b) const
{ 
	if ( (b == 0.0 || ( (a == std::numeric_limits<B>::max()) && (b == -1) ) ))
	{
		throw FloatingPointException(); 
	}
}

template<typename T>
template<typename B>
void TOperand<T>::checkMulOverflow(B a, B b) const
{ 
	if (a > std::numeric_limits<B>::max() / b)
		throw ValueUnderflowException(); 
	if ((a < std::numeric_limits<B>::min() / b))
		throw ValueUnderflowException(); 
}

template<typename T>
template<typename B>
void TOperand<T>::checkSubOverflow(B a, B b) const
{ 
	if ((a < 0.0) == (b < 0.0)
			&& std::abs(b) > std::numeric_limits<B>::min() + std::abs(a)) {
		a < 0.0 ? throw ValueUnderflowException() : throw ValueOverflowException();
	}
} 

template<typename T>
template<typename B>
void TOperand<T>::checkAddOverflow(B a, B b) const
{ 
	if ((a < 0) == (b < 0)
			&& std::abs(b) > std::numeric_limits<B>::max() - std::abs(a)) {
		a < 0.0 ? throw ValueUnderflowException() : throw ValueOverflowException();
	}
} 

template<typename T>
template<typename B>
std::pair<B, B>	TOperand<T>::check_exceptions(TOperand const & rhs,
		void (TOperand<T>::*meth) (B a, B b)const) const
{
	if (!std::isnormal(this->_n) || !std::isnormal(rhs._n))
		;
	B a = static_cast< B >(this->_n);
	B b = static_cast< B >(rhs._n);
	(this->*meth)(a, b);
	return std::make_pair(a, b);
}

	template<typename T>
std::ostream & operator<<(std::ostream & o, TOperand<T> const & rhs)
{
	o << rhs.get_value(); 
	return o;
}

template<typename T>
template<typename B>
IOperand const * TOperand<T>::CreateOperand(B value) const
{
	return new TOperand<T>(value);
}

template<typename T>
IOperand const * TOperand<T>::operator-( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	auto t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t), decltype(t)) const = &TOperand<T>::checkSubOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t)>(a + b);
}

template<typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);

	auto t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t), decltype(t)) const = &TOperand<T>::checkAddOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t)>(a + b);
}

template<typename T>
IOperand const * TOperand<T>::operator*( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	auto t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t), decltype(t)) const = &TOperand<T>::checkMulOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t)>(a * b);
}


template<typename T>
IOperand const * TOperand<T>::operator/( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	auto t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t), decltype(t)) const = &TOperand<T>::checkDivOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t)>(a / b);
}


template<typename T>
IOperand const * TOperand<T>::operator%( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	auto t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t), decltype(t)) const = &TOperand<T>::checkModOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t)>(fmod(a, b));
}

/* ... */

#endif
