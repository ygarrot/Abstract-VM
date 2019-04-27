/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:13:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/26 13:04:24 by ygarrot          ###   ########.fr       */
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
	ENTIER,
	V,
	Sep
};

class Computor;
/* std::function<int(B*nt)> fun = &B::func */
/* typedef std::function< */
typedef std::function<void(Computor*)> meth;
typedef std::map<std::string, meth> func_tab_t;

class Token
{
	public:
		Token(TokenType type, std::string str): _type(type), _str(str){};
		std::string get_str()  { return _str;};
		void set_str(std::string str) { _str = str;};
		void set_type(TokenType type) { _type = type;};
		TokenType get_type() const { return _type;};
		const IOperand * op;
		std::function<void(Computor*)> method;
		std::function<void(Computor*, IOperand const * rhs)> f;
	private:
		TokenType _type;
		std::string _str;
};


#endif
