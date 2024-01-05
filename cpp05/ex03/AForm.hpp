/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:25:12 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:25:12 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{

	public:
		AForm();
		AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& obj);

		virtual ~AForm();

		const std::string&	getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat& b);
		virtual	void		execute(const Bureaucrat& executor) const = 0;
	
	protected:
		void				checkIfExecutable(const Bureaucrat& executor) const;
	
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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, AForm& rhs);

#endif