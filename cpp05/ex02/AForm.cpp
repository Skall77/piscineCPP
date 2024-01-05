/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:25:15 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* Constructor, Destructor, copy */

AForm::AForm() : _name(""), _grade_to_sign(1), _grade_to_execute(1)
{
	this->_is_signed = false;
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute): 
_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = false;
	if(grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	
	std::cout << "constructor with the name " << this->_name << " called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _grade_to_sign(copy._grade_to_sign),
_grade_to_execute(copy._grade_to_execute)
{
	this->_is_signed = copy._is_signed;
}

AForm& AForm::operator=(const AForm& obj)
{
	this->_is_signed = obj._is_signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

/* class functions */

const std::string& AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

bool AForm::isSigned() const
{
	return (this->_is_signed);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

void AForm::checkIfExecutable(const Bureaucrat& executor) const
{
	if(executor.getGrade() > _grade_to_execute)
		throw GradeTooLowException();
	if (!this->_is_signed)
		throw NotSignedException();
}

/* exceptions */

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("You must sign the form before being able to execute it");
}

/* << insertion operator */

std::ostream& operator<<(std::ostream& out, AForm& rhs)
{
	out << "Form name : " << rhs.getName() << " | Signed : ";
	if (rhs.isSigned())
		out << "yes";
	else
		out << "no";
	out << " | Grade needed to sign: " << rhs.getGradeToSign();
	out << " | Graded needed to Execute: " << rhs.getGradeToExecute();

	return (out);
}













