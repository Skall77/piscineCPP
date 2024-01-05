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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	srand(time(NULL));

	Bureaucrat	Bob("Bob", 1);
	Bureaucrat	Alex("Alex", 150);
	AForm 		*form = NULL;
	std::cout << std::endl;
	/* Try to execute a form not signed */
	try 
	{
		form = new PresidentialPardonForm("Mark");
		form->execute(Bob);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
	std::cout << std::endl;
	/* Try to execute a Presidential Pardon Form */
	try
	{
		form = new PresidentialPardonForm("Mark");
		form->beSigned(Bob);
		std::cout << *form << std::endl;
		form->execute(Bob);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
	std::cout << std::endl;
	/* Try to execute without the require grade */
	try
	{
		form = new RobotomyRequestForm("Mark");
		form->beSigned(Bob);
		form->execute(Alex);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
	std::cout << std::endl;
	/* Try to execute a Robotomy Request Form */
	try
	{
		form = new RobotomyRequestForm("Mark");
		form->beSigned(Bob);
		std::cout << *form << std::endl;
		form->execute(Bob);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
	std::cout << std::endl;
	/* Try to execute a Shrubbery Creation Form */
	try
	{
		form = new ShrubberyCreationForm("Mark");
		std::cout << *form << std::endl;
		form->beSigned(Bob);
		form->execute(Bob);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete form;
	}
	std::cout << std::endl;
	
	return (0);
}