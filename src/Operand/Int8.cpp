/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 15:57:13 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Int8.hpp"

Int8::Int8(std::string str) 
{
	_n = stoi(str);
	_str = std::to_string(_n);
	_type = INT8;
}

Int8::~Int8() 
{

}

Int8::Int8(Int8 const &src)
{
	*this = src;
}

Int8     &Int8::operator=(Int8 const & src) 
{
	(void)src;
	return *this;
}

Int8::Int8(int type):TOperand(type){};
Int8::Int8(void):TOperand(){};

