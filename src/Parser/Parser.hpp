/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:36:35 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 11:04:55 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "../Operand/Int8.hpp"
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
		void	setFunction(Token * token);
		void	parse();
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
		IOperand const * createInt8( std::string const & value ) const;
		/* IOperand const * createInt16( std::string const & value ) const; */
		/* IOperand const * createInt32( std::string const & value ) const; */
		/* IOperand const * createFloat( std::string const & value ) const; */
		/* IOperand const * createDouble( std::string const & value ) const; */
		TOKEN_PTR get_tokens(){return _tokens;};
		void set_tokens(TOKEN_PTR tokens){_tokens = tokens;};
	private:
		TOKEN_PTR _tokens;
};
/* std::ostream 		&operator<<(std::ostream & o, Parser const & src); */

#endif
