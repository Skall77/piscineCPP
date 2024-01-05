/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/14 11:39:38 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		std::cout << "///////" << std::endl;
		Fixed a(Fixed(23) + Fixed(1.01f));
		Fixed b(Fixed(23) - Fixed(1.01f));
		Fixed c(Fixed(23) / Fixed(1.01f));

		std::cout <<"a is : " << a << std::endl;
		std::cout <<"b is : " << b << std::endl;
		std::cout <<"c is : " << c << std::endl;
		std::cout << --a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		if (a > b)
			std::cout << "Boolean test 1 work" << std::endl;
		else
			std::cout << "Boolean problem" << std::endl;
		if (c == c)
			std::cout << "Boolean test 2 work" << std::endl;
		else
			std::cout << "Boolean problem" << std::endl;
			
		const Fixed d(555);
		const Fixed e(42);
		std::cout << Fixed::min(d, e) << std::endl;
	}

	return 0;
}