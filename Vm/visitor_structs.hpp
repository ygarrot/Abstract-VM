/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor_structs.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 12:53:13 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/18 16:25:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <boost/variant.hpp>
#include "../Operand/TOperand.hpp"
typedef boost::variant<TOperand<int>> OPVARIANT;

struct add_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() + b.get_value(); };
};


struct sub_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() - b.get_value(); };
};


struct mul_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() * b.get_value(); };
};


struct div_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() / b.get_value(); };
};


struct mod_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() % b.get_value(); };
};


struct print_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T a) const {std::cout<<"tesT"; std::cout << a.get_value() << std::endl; return a;};

};


struct dump_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { return e.get_value() + b.get_value(); };
};


struct assert_visitor : public boost::static_visitor<OPVARIANT>
{
		template<typename T>
		T operator()(T e, T b) const { asser(e == b); };
};

