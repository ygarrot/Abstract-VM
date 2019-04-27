/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:30:23 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/27 11:58:30 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include "IOperand.hpp"
#include "boost/variant.hpp"
# define abstr_variant boost::variant<int8_t, int16_t, int32_t, float, double> 
#include "TOperand.hpp"
#include <map>
#include <regex>

#define NUM "(.*)\\((.*)\\)(.*)"
#endif

