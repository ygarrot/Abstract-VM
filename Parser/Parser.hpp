/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:36:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/19 16:01:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>

enum class Token
{
	Instruction,
	Value,
	N,
	V,
	NL,
	SEP
};

/* typedef struct s_Token */
/* { */
/* 	std::string str; */

/* }				Token; */

class 					Parser
{
	public:
		~Parser(void);
		Parser(void);
		Parser(std::string name);
		Parser(Parser const &src);
		Parser 		&operator=(Parser const & src);
		/* void parse(); */

	private:
};
/* std::ostream 		&operator<<(std::ostream & o, Parser const & src); */

#endif
