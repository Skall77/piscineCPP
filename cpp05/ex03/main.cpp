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
#include "Intern.hpp"

int main()
{
	srand(time(NULL));

	Bureaucrat	Bob("Bob", 1);
	Intern		intern;
	AForm 		*form;

	std::cout << std::endl;
	/* Intern try to create a form who doesn't exist */
	form = intern.makeForm("zdzdadz", "Mark");
	std::cout << std::endl;
	/* Intern try to create presidential pardon */
	form = intern.makeForm("presidential pardon", "Mark");
	std::cout << std::endl;
	std::cout << *form << std::endl;
	try
	{
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
	/* Intern try to create robotomy request */
	form = intern.makeForm("robotomy request", "Mark");
	std::cout << std::endl;
	std::cout << *form << std::endl;
	try
	{
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
	/* Intern try to create shrubbery creation */
	form = intern.makeForm("shrubbery creation", "Mark");
	std::cout << std::endl;
	std::cout << *form << std::endl;
	try
	{
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