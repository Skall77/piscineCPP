/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:04:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void plus_one(int &n)
{
	n += 1;
}

int main()
{
	int arrInt[5] = {0,1,2,3,4};

	::iter(arrInt, 5, &::print_element);
	std::cout << std::endl;
	::iter(arrInt, 5, &plus_one);
	::iter(arrInt, 5, &::print_element);
	std::cout << std::endl;
	::iter(arrInt, 5, &plus_one);
	::iter(arrInt, 5, &plus_one);
	::iter(arrInt, 5, &plus_one);
	::iter(arrInt, 5, &::square);
	::iter(arrInt, 5, &::print_element);
	std::cout << std::endl;

	double arrDouble[5] = {0.0, 0.5, 1.5, 2.5, -3.4};
	::iter(arrDouble, 5, &::print_element);
	std::cout << std::endl;
	::iter(arrDouble, 5, &::square);
	::iter(arrDouble, 5, &::print_element);
	std::cout << std::endl;

	std::string arrString[5] = { "Hi,", "This", "is", "a CPP", "module"};
	::iter(arrString, 5, &::print_element);
	return (0);
}