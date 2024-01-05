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

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	Bob("Bob", 1);
		Form		F42("F42", 150, 150);
		std::cout << std::endl;
		std::cout << F42 << std::endl;
		std::cout << Bob << std::endl;
		std::cout << std::endl;
		Bob.signForm(F42);
		std::cout << std::endl;
		std::cout << F42 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Form F31("F31", 0, 1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Form F32("F32", 151, 1);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Form F33("F33", 150, 0);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Form F34("F34", 49, 151);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	Bureaucrat Ashley("Ashley", 140);
	Form F39("F39", 39, 150);
	std::cout << std::endl;
	std::cout << F39 << std::endl;
	std::cout << Ashley << std::endl;
	std::cout << std::endl;
	Ashley.signForm(F39);
	std::cout << std::endl;

	return (0);
}