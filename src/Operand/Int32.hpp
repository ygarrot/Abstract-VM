/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:30:06 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Int32: public TOperand<int32_t>
{
	public:
		Int32(void);
		Int32(std::string);
		Int32(int type);
		Int32(Int32 const & src);
		Int32 &operator=(Int32 const & src);
		~Int32(void);
	private:
};

#endif
