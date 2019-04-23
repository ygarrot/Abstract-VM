/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:42:41 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Double.hpp"

Double::Double(std::string str) : TOperand<double>(str, stod(str), DOUBLE)
{
}

Double::~Double() 
{

}

Double::Double(Double const &src)
{
	*this = src;
}

Double     &Double::operator=(Double const & src) 
{
	(void)src;
	return *this;
}

Double::Double(void):TOperand(){};

