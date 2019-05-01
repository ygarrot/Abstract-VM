/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Computor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:42:52 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/01 15:21:02 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ABSTRACT_VM_COMPUTOR_H
#define ABSTRACT_VM_COMPUTOR_H

#include "../Operand/TOperand.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include "../Exceptions/Exceptions.hpp"
#include "../Lexer/Token.hpp"
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <numeric>
#include <assert.h>     /* assert */

class Token;
#define OP_PTR std::vector< std::shared_ptr<const IOperand > > 
#define TOKEN_PTR std::vector< std::shared_ptr<Token> >
class Computor
{
	public:
		Computor &operator=(Computor const & src);
		Computor(){};
		Computor(bool verbose) : _verbose(verbose){};
		Computor(std::string){};
		Computor(Computor const & src){(void)src;};
		~Computor(void){};
		OP_PTR get_elem(size_t n);
		void		push(IOperand const * op);
		void		pop();
		void		dump();
		void		ft_assert(IOperand const * op);
		void		add();
		void		sub();
		void		mul();
		void		div();
		void		mod();
		void		print();
		void		visit();
		void		exit();

		void		min();
		void		max();

		void		ft_or();
		void		ft_and();
		void		ft_xor();

		void		check_stack(size_t size);
		TOKEN_PTR get_tokens(){return _tokens;};
		void set_tokens(TOKEN_PTR tokens){_tokens = tokens;};
		void	displayFuncName(Token *token);
		void	verboseOneArg(IOperand const & op);
		void	verboseTwoArg(Token *token, OP_PTR op);
	private:
		bool	_verbose;
		OP_PTR _stack;
		TOKEN_PTR	_tokens;
};

#endif


