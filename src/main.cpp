/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 12:50:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer/Lexer.hpp"
#include "./Parser/Parser.hpp"

int main(int ac, char **av)
{
	Lexer l;
	Parser p;
	Computor c;

	try
	{
		ac > 1  ? l.lex(av[1]) : l.lex();
		p.set_tokens(l.get_tokens());
		p.parse();
		c.set_tokens(p.get_tokens());
		c.visit();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
