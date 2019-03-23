/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/23 13:17:35 by ygarrot          ###   ########.fr       */
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
		virtual int getPrecision( void ) const {return (1);}; // Precision of the type of the instance
		virtual eOperandType getType( void ) const { return INT8;}; // Type of the instance
		/* eOperandType getType( void ){}; // Type of the instance */
		virtual void check_exceptions(TOperand const & rhs) const;
		/* virtual void check_underflow(IOperand const & rhs); */
		/* virtual void check_overflow(TOperand const & rhs); */
		virtual IOperand const * operator+( IOperand const & rhs ) const;
		/* virtual IOperand const * operator+( IOperand const & rhs ) const;//{(void)rhs;return new TOperand<T>();}; // Sum */
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();}; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();}; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();}; // Modulo
		virtual std::string const & toString( void ) const {return this->_str;}; // String representation of the instance
		IOperand &operator=(IOperand const & src){(void)src; return *this;};
		TOperand(){};
		TOperand(std::string){};
		TOperand(T type){this->_n = type;};
		TOperand(TOperand const & src){(void)src;};
		~TOperand(void){};
		int		get_value(void) const {return this->_n;};
	private:
		std::string _str;
		T _n;
};


bool mulOverflow(long long a, long long b) 
{ 
	long long result = a * b; 
	if (a == 0 || b == 0)  
		;
	if (a == result / b) 
		;
	else
		;
	return true;
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
	if ( (a < 0.0) == (b < 0.0)
			&& ( b ) > std::numeric_limits<double>::max() - std::abs( a ) ) {
		//  Addition would overflow...
	}
	return 1;
} 

	template<typename T>
void TOperand<T>::check_exceptions(TOperand const & rhs) const
{
	if (!std::isnormal(this->_n) || !std::isnormal(rhs._n))
		;
	subOvf<T>(this->_n, rhs._n);
	(void)rhs;
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
	(void)rhs;
	check_exceptions(tmp);
	return (new TOperand<T>(this->_n - reinterpret_cast< const TOperand<T>& >(rhs)._n));
}

template <typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	TOperand<T> const & tmp = reinterpret_cast< const TOperand<T>& >(rhs);
	(void)rhs;
	check_exceptions(tmp);
	return (new TOperand<T>(this->_n + tmp._n));
}

#endif
