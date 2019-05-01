/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:13:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/01 14:46:52 by ygarrot          ###   ########.fr       */
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

typedef struct s_verbose
{
	std::string	func_name;
	std::string	op;
	meth		method;
	std::function<void(Computor*, IOperand const * rhs)>	f;
}		t_verbose;

class Token
{
	public:
		Token(TokenType type, std::string str, int line);
		int get_line();
		void set_line(int line);
		std::string get_str();
		void set_str(std::string str);
		void set_type(TokenType type);
		TokenType get_type() const;
		const IOperand  *op;
		t_verbose verbose;
	private:
		TokenType	_type;
		std::string	_str;
		int			_line;
};
#endif
