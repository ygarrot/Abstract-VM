/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:03:50 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 16:19:50 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <sstream>
#include <iostream>
#include <vector>

#define N "[-]?[0..9]+"

#define Z "[-]?[0..9]+.[0..9]+"

#define SEP "'\n'+"

class 					Lexer
{
	public:
		~Lexer(void);
		Lexer(void);
		Lexer(std::string name);
		Lexer(Lexer const &src);
		Lexer 		&operator=(Lexer const & src);
		void Lex(std::string toParse);
	private:
};
/* std::ostream 		&operator<<(std::ostream & o, Lexer const & src); */

#endif
