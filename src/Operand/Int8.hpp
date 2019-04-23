/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:29:41 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_H
#define INT8_H

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Int8: public TOperand<int8_t>
{
	public:
		Int8(void);
		Int8(std::string);
		Int8(int type);
		Int8(Int8 const & src);
		Int8 &operator=(Int8 const & src);
		~Int8(void);
	private:
};


#endif
