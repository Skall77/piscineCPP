/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:25:06 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/25 17:25:06 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string& RobotomyRequestForm::getTarget(void) const
{
	return(this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->checkIfExecutable(executor);
	std::cout << "* DRILLING NOIIIISES *" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
