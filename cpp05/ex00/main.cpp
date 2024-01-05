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
	Bureaucrat Bob("Bob", 1);
	Bureaucrat Ashley("Ashley", 150);
	std::cout << std:: endl;

	std::cout << Bob << std::endl;
	std::cout << Ashley << std::endl;

	std::cout << std:: endl;
	try
	{
		Bureaucrat Mark("Mark", 0);
	}
	catch(std::exception& e)
	{
		std::cout << "Can't create Mark" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Bureaucrat Thomas("Thomas", 15000);
	}
	catch(std::exception& e)
	{
		std::cout << "Can't create Thomas" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Bob.incrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << "Can't increment Bob's grade" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	try
	{
		Ashley.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cout << "Can't decrement Ashley's grade" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std:: endl;
	Bob.decrementGrade();
	Ashley.incrementGrade();
	std::cout << Bob << std::endl;
	std::cout << Ashley << std::endl;
	std::cout << std:: endl;
	return (0);
}