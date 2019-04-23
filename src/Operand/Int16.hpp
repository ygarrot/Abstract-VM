/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:26:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_H
#define INT16_H

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Int16: public TOperand<int16_t>
{
	public:
		Int16(void);
		Int16(std::string);
		Int16(int type);
		Int16(Int16 const & src);
		Int16 &operator=(Int16 const & src);
		/* TOperand &operator=(TOperand const & src){(void)src; return *this;}; */
		~Int16(void);
	private:
};

#endif
