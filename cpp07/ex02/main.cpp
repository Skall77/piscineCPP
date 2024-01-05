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

#include "Array.hpp"

int main()
{
	Array<int> a;
	try
	{
		std::cout << a[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "size of array a is : " << a.size() << std::endl;
	std::cout << std::endl;
	Array<std::string> arr(5);
	std::cout << std::endl;
	try
	{
		arr[0] = "Hi!";
		arr[1] = "This";
		arr[2] = "is a";
		arr[3] = "CPP";
		arr[4] = "Module";
		arr[5] = "!";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "size of array arr is : " << arr.size() << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
	Array<std::string> arr_copy(arr);
	arr_copy[0] = "Hello";
	std::cout << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < arr_copy.size(); i++)
		std::cout << arr_copy[i] << std::endl;
	std::cout << std::endl;
	arr = arr_copy;
	arr_copy[0] = "HEY!";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	std::cout << std::endl;
	
	return (0);
}