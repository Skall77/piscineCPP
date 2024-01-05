/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	{
		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;
		
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	{
		std::cout << "///////" << std::endl;
		Fixed d;

		std::cout << d.getRawBits() << std::endl;
		d.setRawBits(84848);
		std::cout << d.getRawBits() << std::endl;
		Fixed e(d);
		Fixed f;
		f = d;
		std::cout << e.getRawBits() << std::endl;
		std::cout << f.getRawBits() << std::endl;
		
	}
	return 0;
}