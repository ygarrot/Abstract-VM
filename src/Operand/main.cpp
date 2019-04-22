/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:13:28 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/22 12:05:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TOperand.hpp"
#include "Int8.hpp"
#include <iostream>

int main(void)
{
	/* TOperand<double> test(std::numeric_limits<double>::min()); */
	TOperand<int> test(2.0);
	TOperand<int> test3(2.0);
	/* Int8 test3(INT_MAX); */
	/* TOperand<int> test; */

	const TOperand<int> *test2 =  reinterpret_cast<const TOperand<int> * >(test * test3);
	std::cout << *test2 << std::endl;

	TOperand<int> testint(INT_MAX);
	TOperand<int> testint2(INT_MAX);
	/* Int8 test3(INT_MAX); */
	/* TOperand<int> test; */

	const TOperand<int> *testint3 =  reinterpret_cast<const TOperand<int> * >(test + test3);
	std::cout << *testint3 << std::endl;

	std::cout << "hello world2" << std::endl;

}
