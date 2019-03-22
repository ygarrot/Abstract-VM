/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:28 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/22 17:24:33 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TOperand.hpp"
#include "Int8.hpp"
#include <iostream>

int main(void)
{
	Int8 test(1);
	/* TOperand<int> test; */

	const TOperand<int> *test2 =  reinterpret_cast<const TOperand<int> * >(test + test);
	std::cout << *test2;
	std::cout << "hello world" << std::endl;

}
