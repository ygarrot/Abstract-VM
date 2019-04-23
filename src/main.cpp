/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:04:06 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "../Parser/Parser.hpp"

int main(int ac, char **av)
{
	Lexer l;
	Parser p;
	Computor c;

	l.lex(ac > 1 ? av[1]: "./example.avm");
	p.set_tokens(l.get_tokens());
	p.parse();
	c.set_tokens(p.get_tokens());
	c.visit();
}
