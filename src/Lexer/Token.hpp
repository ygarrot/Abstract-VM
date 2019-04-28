/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:13:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/28 12:43:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../Operand/IOperand.hpp"
#include "../Vm/Computor.hpp"
#include <map>
#include <iostream>

enum class TokenType
{
	Instruction,
	Value,
	Entier,
	Ima,
	Sep
};

class Computor;
typedef std::function<void(Computor*)> meth;
typedef std::map<std::string, meth> func_tab_t;

class Token
{
	public:
		static std::string print_line_error(int line, std::string error)
		{
			return "Line : " + std::to_string(line) + error;
		};
		Token(TokenType type, std::string str, int line): _type(type), _str(str), _line(line){};
		int get_line()  { return _line;};
		void set_line(int line)  { _line = line;};
		std::string get_str()  { return _str;};
		void set_str(std::string str) { _str = str;};
		void set_type(TokenType type) { _type = type;};
		TokenType get_type() const { return _type;};
		const IOperand * op;
		meth						method;
		std::function<void(Computor*, IOperand const * rhs)>	f;
	private:
		TokenType	_type;
		std::string	_str;
		int			_line;
};

#endif
