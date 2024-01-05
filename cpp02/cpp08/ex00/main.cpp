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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) 
{
	/*Good test with vector */
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try
	{
		std::vector<int>::iterator vec_it = easyfind(vec, 8);
		std::cout << "Found: " << *(vec_it) << " followed by " << *(++vec_it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	/*Bad test with vector */
	try
	{
		std::vector<int>::iterator vec_it = easyfind(vec, 18);
		std::cout << "Found: " << *(vec_it) << " followed by " << *(++vec_it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	/*wrong test with list */
	std::list<int> list;
	for (int i = 15; i < 25; i++)
		list.push_back(i);
	try
	{
		std::list<int>::iterator list_it = easyfind(list, 21);
		std::cout << "Found: " << *(list_it) << " followed by " << *(++list_it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	/*wrong test with list */
	try
	{
		std::list<int>::iterator list_it = easyfind(list, 5);
		std::cout << "Found: " << *(list_it) << " followed by " << *(++list_it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return(0);
}