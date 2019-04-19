/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/18 16:32:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_TOPERAND_HPP
#define ABSTRACT_VM_TOPERAND_HPP

#include <cfenv>
#include <iostream>
#include <cmath>
#include "IOperand.hpp"
#include <cstdint>

template<typename T>
class TOperand: public IOperand {
	public:
		IOperand &operator=(IOperand const & src);
		TOperand(){};
		TOperand(std::string){};
		TOperand(T type){this->_n = type;};
		TOperand(TOperand const & src){(void)src;};
		~TOperand(void){};
		T		get_value(void) const {/*std::cout <<this->_n ;*/return this->_n;};
		virtual	int getPrecision( void ) const;
		virtual	eOperandType getType( void ) const;
		virtual void	check_exceptions(TOperand const & rhs) const;
		virtual	IOperand const * operator+( IOperand const & rhs ) const;
		virtual	IOperand const * operator-( IOperand const & rhs ) const;
		virtual	IOperand const * operator*( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();};
		virtual	IOperand const * operator/( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();};
		virtual	IOperand const * operator%( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();};
		virtual	std::string const & toString( void ) const;
	private:
		std::string _str;
		T _n;
		eOperandType _type;
};

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
	std::cout << std::exp(a - b) << std::endl;
	if (std::fetestexcept(FE_OVERFLOW))
		std::cout << "overflow";
	if (std::fetestexcept(FE_UNDERFLOW))
		std::cout << "underflow";
	return 1;
} 

	template<typename T>
int addOvf(T a, T b) 
{ 
	if ((a < 0.0) == (b < 0.0)
			&& std::abs(b) > std::numeric_limits<double>::max() - std::abs(a)) {
	}
	return 1;
} 

	template<typename T>
void TOperand<T>::check_exceptions(TOperand const & rhs) const
{
	if (!std::isnormal(this->_n) || !std::isnormal(rhs._n))
		;
	subOvf<T>(this->_n, rhs._n);
}

	template<typename T>
std::ostream & operator<<(std::ostream & o, TOperand<T> const & rhs)
{
	o << rhs.get_value(); 
	return o;
}

template <typename T>
IOperand const * TOperand<T>::operator-( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	check_exceptions(tmp);
	return (new TOperand<T>(this->_n - tmp._n));
}

template <typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	check_exceptions(tmp);
	return new TOperand<T>(this->_n + tmp._n);
}

/* ... */

#endif
