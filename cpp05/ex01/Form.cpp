/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:25:15 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:15 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* Constructor, Destructor, copy */

Form::Form() : _name(""), _grade_to_sign(1), _grade_to_execute(1)
{
	this->_is_signed = false;
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute): 
_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = false;
	if(grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	
	std::cout << "Form constructor with the name " << this->_name << " called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _grade_to_sign(copy._grade_to_sign),
_grade_to_execute(copy._grade_to_execute)
{
	this->_is_signed = copy._is_signed;
}

Form& Form::operator=(const Form& obj)
{
	this->_is_signed = obj._is_signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

/* class functions */

const std::string& Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

bool Form::isSigned() const
{
	return (this->_is_signed);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw GradeTooLowException();
	this->_is_signed = true;
}

/* exceptions */

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/* << insertion operator */

std::ostream& operator<<(std::ostream& out, Form& rhs)
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













