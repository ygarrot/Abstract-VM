/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:54:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/21 16:19:02 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include "../Parser/Parser.hpp"

int main()
{
	Lexer l;
	Parser p;
	Computor c;

	l.lex("../example.avm");
	p.set_tokens(l.get_tokens());
	p.parse();
	c.set_tokens(p.get_tokens());
	c.visit();
	std::cout << "hello world !" << std::endl;
}
