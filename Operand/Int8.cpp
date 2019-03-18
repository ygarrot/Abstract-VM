//
// Created by Yoan GARROT on 2019-03-17.
//

#include "Int8.h"

IOperand const * Int8::operator+( IOperand const & rhs ) const
{
	return new Int8(this->toString() + rhs.toString());
}

/* virtual int getPrecision( void ) const = 0; // Precision of the type of the instance */
/* virtual eOperandType getType( void ) const = 0; // Type of the instance */
/* virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference */
/* virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product */
/* virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient */
/* virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo */
/* virtual std::string const & toString( void ) const = 0; // String representation of the instance */
/* virtual ~IOperand( void ) {} */
