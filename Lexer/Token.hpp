/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:13:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/20 15:26:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "../Operand/IOperand.hpp"
#include "../Vm/Computor.hpp"
#include <iostream>

enum class TokenType
{
	Instruction,
	Value,
	N,
	V,
	Sep
};

typedef void (Computor::*op_func)();
typedef std::map<std::string, op_func> func_tab_t ;

class Token
{
	public:
		Token(TokenType type, std::string str): _type(type), _str(str){};
		std::string get_str()  { return _str;};
		void set_str(std::string str) { _str = str;};
		void set_type(TokenType type) { _type = type;};
		TokenType get_type() const { return _type;};
		union
		{
			std::shared_ptr<const IOperand *> op;
			union
			{
				public:
				op_func method;
				void (Computor::*f)(IOperand const * rhs);
			};
		};
	private:
			TokenType _type;
			std::string _str;
};


#endif
