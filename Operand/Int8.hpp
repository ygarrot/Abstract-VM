//
// Created by Yoan GARROT on 2019-03-17.
//

#ifndef ABSTRACT_VM_INT8_H
#define ABSTRACT_VM_INT8_H


#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Int8: public TOperand<int>
{
	public:
		virtual eOperandType getType( void ) const { return INT8;}; // Type of the instance
		/* eOperandType getType( void ){}; // Type of the instance */
		/* virtual void check_exceptions(IOperand const & rhs); */
		/* virtual void check_underflow(IOperand const & rhs); */
		/* virtual void check_overflow(IOperand const & rhs); */
		Int8(void):TOperand(){};
		Int8(std::string){};
		Int8(int type):TOperand(type){};
		Int8(Int8 const & src){(void)src;};
		IOperand &operator=(IOperand const & src){(void)src; return *this;};
		/* TOperand &operator=(TOperand const & src){(void)src; return *this;}; */
		~Int8(void){};
	private:
		std::string stri;
		/* int8_t _n; */
};


#endif
