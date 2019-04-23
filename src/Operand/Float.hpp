/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:31:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Float: public TOperand<float>
{
	public:
		Float(void);
		Float(std::string);
		Float(int type);
		Float(Float const & src);
		Float &operator=(Float const & src);
		/* TOperand &operator=(TOperand const & src){(void)src; return *this;}; */
		~Float(void);
	private:
};

#endif
