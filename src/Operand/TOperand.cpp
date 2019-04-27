/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperand.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:43:15 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/26 11:55:06 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "TOperand.hpp" */

template<typename T>
template<typename B>
IOperand const * TOperand<T>::CreateOperand(eOperandType type, B value) const
{
	return OpFactory->createOperand(type, std::to_string(value));
}

	template<typename T>
auto TOperand<T>::get_highest_prec(TOperand<T> const & rhs) const
{
	if (rhs._type > this->_type)
		return rhs; 
	return *this; 
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
IOperand const * TOperand<T>::operator-( IOperand const & rhs ) const
{
	TOperand const & tmp = reinterpret_cast< const TOperand & >(rhs);
	TOperand t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t._n), decltype(t._n)) const = &TOperand<T>::checkSubOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t._n)>(t._type, a - b);
}

template<typename T>
IOperand const * TOperand<T>::operator+( IOperand const & rhs ) const
{
	TOperand const & tmp = reinterpret_cast< const TOperand & >(rhs);

	TOperand t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t._n), decltype(t._n)) const = &TOperand<T>::checkAddOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t._n)>(t._type, a + b);
}

template<typename T>
IOperand const * TOperand<T>::operator*( IOperand const & rhs ) const
{
	TOperand const & tmp = reinterpret_cast< const TOperand & >(rhs);
	TOperand t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t._n), decltype(t._n)) const = &TOperand<T>::checkMulOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t._n)>(t._type, a * b);
}


template<typename T>
IOperand const * TOperand<T>::operator/( IOperand const & rhs ) const
{
	TOperand const & tmp = reinterpret_cast< const TOperand & >(rhs);
	TOperand t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t._n), decltype(t._n)) const = &TOperand<T>::checkDivOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t._n)>(t._type, a / b);
}


template<typename T>
IOperand const * TOperand<T>::operator%( IOperand const & rhs ) const
{
	TOperand const & tmp = reinterpret_cast< const TOperand & >(rhs);
	TOperand t = get_highest_prec(tmp);
	void (TOperand<T>::*f)( decltype(t._n), decltype(t._n)) const = &TOperand<T>::checkModOverflow;
	auto [a, b] = check_exceptions(tmp, f);
	return CreateOperand<decltype(t._n)>(t._type, fmod(a, b));
}

void TemporaryFunction ()
{
	    TOperand<int> TempObj;
}
