//
// Created by Yoan GARROT on 2019-03-17.
//

#ifndef ABSTRACT_VM_INT8_H
#define ABSTRACT_VM_INT8_H


#include <iostream>
#include "IOperand.hpp"
#include <cstdint>

class Int8: public IOperand {
	public:
		virtual int getPrecision( void ) const ; // Precision of the type of the instance
		/* eOperandType getType( void ); // Type of the instance */
		virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
		virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
		virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
		virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
		virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo
		virtual std::string const & toString( void ) const; // String representation of the instance
		Int8(){};
		Int8(std::string){};
		Int8(Int8 const & src);
		~Int8(void);
	private:
		int8_t _n;
};


#endif //ABSTRACT_VM_INT8_H
