/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:42:28 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Int32.hpp"

Int32::Int32(std::string str) : TOperand<int32_t>(str, stoi(str), INT32)
{
}

Int32::~Int32() 
{

}

Int32::Int32(Int32 const &src)
{
	*this = src;
}

Int32     &Int32::operator=(Int32 const & src) 
{
	(void)src;
	return *this;
}

Int32::Int32(void):TOperand(){};

