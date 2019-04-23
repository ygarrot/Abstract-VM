/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/23 16:28:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include <iostream>
#include "TOperand.hpp"
#include <cstdint>

class Double: public TOperand<double>
{
	public:
		Double(void);
		Double(std::string);
		Double(int type);
		Double(Double const & src);
		Double &operator=(Double const & src);
		~Double(void);
	private:
};

#endif
