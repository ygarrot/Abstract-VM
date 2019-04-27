/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/27 13:44:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer/Lexer.hpp"
#include "./Parser/Parser.hpp"

int main(int ac, char **av)
{
	Lexer l;
	Parser p;
	Computor c;

	std::string file_name = ac > 1 ? av[1]: "./example.avm";
	std::cout << file_name  + "\n";
	l.lex(file_name);
	p.set_tokens(l.get_tokens());
	p.parse();
	c.set_tokens(p.get_tokens());
		c.visit();
	/* try */ 
	/* { */
	/* } */
	/* catch (std::exception e) */
	/* { */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
}
