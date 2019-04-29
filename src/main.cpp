/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 13:49:50 by ygarrot          ###   ########.fr       */
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
		int ret = ac > 1  ? l.lex(av[1]) : l.lex();
		p.set_tokens(l.get_tokens());
		if (p.parse() < 0 || ret < 0)
			return EXIT_FAILURE;
		c.set_tokens(p.get_tokens());
		c.visit();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
