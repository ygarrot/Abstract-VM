/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:42:08 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Int16.hpp"

Int16::Int16(std::string str) : TOperand<int16_t>(str, stoi(str), INT16)
{
}

Int16::~Int16() 
{

}

Int16::Int16(Int16 const &src)
{
	*this = src;
}

Int16     &Int16::operator=(Int16 const & src) 
{
	(void)src;
	return *this;
}

Int16::Int16(void):TOperand(){};

