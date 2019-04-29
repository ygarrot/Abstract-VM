/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:36:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 11:53:38 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "../Operand/TOperand.hpp"
#include "../Operand/OperandFactory.hpp"
#include "../Lexer/Lexer.hpp"
#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <stdexcept>

class Int8;

class 					Parser
{
	public:
		~Parser(void);
		Parser(void);
		Parser(std::string name);
		Parser(Parser const &src);
		Parser 		&operator=(Parser const & src);
		IOperand const *CreateOperand(std::string str) const;
		void	setFunction(Token * token, bool & value_expected);
		void	parse();
		TOKEN_PTR get_tokens();
		void set_tokens(TOKEN_PTR tokens);
	private:
		TOKEN_PTR _tokens;
};
/* std::ostream 		&operator<<(std::ostream & o, Parser const & src); */

#endif
