/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:48:46 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 11:52:25 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token(TokenType type, std::string str, int line) :
	_type(type),
	_str(str),
	_line(line)
{}

int	Token::get_line()
{
	return _line;
}

void	Token::set_line(int line)
{
	_line = line;
}

std::string	Token::get_str()
{
	return _str;
}

void	Token::set_str(std::string str)
{
	_str = str;
}

void	Token::set_type(TokenType type)
{
	_type = type;
}

TokenType	Token::get_type() const
{
	return _type;
}

