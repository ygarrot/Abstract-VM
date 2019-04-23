/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:41:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Float.hpp"

Float::Float(std::string str) : TOperand<float>(str, stof(str), FLOAT)
{
}

Float::~Float() 
{

}

Float::Float(Float const &src)
{
	*this = src;
}

Float     &Float::operator=(Float const & src) 
{
	(void)src;
	return *this;
}

Float::Float(void):TOperand(){};

