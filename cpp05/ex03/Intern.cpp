/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:57:47 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/26 09:57:47 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	AForm* ret;
	std::string form_names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i;

	for (i = 0; i < 3; i++)
		if(form_names[i] == form_name)
			break;

	switch (i)
	{
		case 0:
			ret = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		case 1:
			ret = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		case 2:
			ret = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		default:
			ret = NULL;
			std::cout << "Intern can't create a Form that doesn't exist" << std::endl;
	}
	return (ret);
}
