/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:17:55 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/01 10:17:55 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <stdlib.h>

class RPN
{
	public:

		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& obj);

		~RPN();

		int 	getResult(void) const;
		void	makeRPN(const std::string& expression);
		void	calculate(int n1, int n2, char op);

		class NoDivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

		class TwoOperandsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };


	private:
		std::stack<int> _expression;
		int				_result;
};

#endif