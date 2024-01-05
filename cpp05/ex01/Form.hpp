/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:25:12 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:12 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{

	public:
		Form();
		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		Form(const Form& copy);
		Form& operator=(const Form& obj);

		~Form();

		const std::string&	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat& b);
	
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

		class GradeTooHighException : public std::exception
		{	
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, Form& rhs);

#endif