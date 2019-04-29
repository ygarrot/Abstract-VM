/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:12:24 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 12:04:09 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"
TokenException::TokenException(std::string defaul, int line):
	_default(defaul)
{
	set_str(line);
}

TokenException::TokenException():
	_str(_default)
{
}

TokenException::TokenException(int line)
{
	set_str(line);
}

TokenException::TokenException(TokenException const &src)
{
	_str = src._str;
}

TokenException & TokenException::operator=(TokenException const & src)
{
	_str = src._str;
	return *this;
}

void TokenException::set_str(int line)
{
	_str = std::string(RED) + "Line : " + std::to_string(line) + " Error : " + _default  + std::string(RESET);
}

TokenException::~TokenException(void) throw()
{
}

const char * TokenException::what(void) const throw()
{
	return _str.c_str();
}

