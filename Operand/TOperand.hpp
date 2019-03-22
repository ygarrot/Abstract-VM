/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:09:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/22 17:24:53 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_TOPERAND_HPP
#define ABSTRACT_VM_TOPERAND_HPP


#include <iostream>
#include "IOperand.hpp"
#include <cstdint>

template<typename T>
class TOperand: public IOperand {
	public:
		virtual int getPrecision( void ) const {return (1);}; // Precision of the type of the instance
		virtual eOperandType getType( void ) const { return INT8;}; // Type of the instance
		/* eOperandType getType( void ){}; // Type of the instance */
		/* virtual void check_exceptions(IOperand const & rhs); */
		/* virtual void check_underflow(IOperand const & rhs); */
		/* virtual void check_overflow(IOperand const & rhs); */
		virtual IOperand const * operator+( IOperand const & rhs ) const;//{(void)rhs;return new TOperand<T>();}; // Sum
		/* virtual IOperand const * operator+( IOperand const & rhs ) const;//{(void)rhs;return new TOperand<T>();}; // Sum */
		virtual IOperand const * operator-( IOperand const & rhs ) const{(void)rhs;return new TOperand<T>();}; // Difference
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

	template<typename T>
std::ostream & operator<<(std::ostream & o, TOperand<T> const & rhs)
{
	o << rhs.get_value(); 
	return o;
}

template <typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	(void)rhs;
	/* check_exceptions(rhs); */
	/* return new TOperand<T>(); */
	return (new TOperand<T>(this->_n + reinterpret_cast< const TOperand<T>& >(rhs)._n));
}

#endif
