/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:17:41 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/01 10:17:41 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN(): _result(0)
{
}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN& obj)
{
	this->_expression = obj._expression;
	this->_result = obj._result;
	return (*this);
}

RPN::~RPN()
{
}

int RPN::getResult(void) const
{
	return (this->_result);
}

void RPN::makeRPN(const std::string& expression)
{
	std::string token;

	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];
		if (c == ' ' || c == '\t')
			continue;
		else if (isdigit(c))
			token += c;
		else if (c == '+' || c == '-' || c == '/' || c == '*')
		{
			if (this->_expression.size() < 2)
				throw TwoOperandsException();
			int n2 = this->_expression.top();
			this->_expression.pop();
			int n1 = this->_expression.top();
			this->_expression.pop();
			calculate(n1, n2, c);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		if(!token.empty())
		{
			this->_expression.push(atoi(token.c_str()));
			token.clear();
		}
	}
	if (this->_expression.size() != 1)
		throw TwoOperandsException();
	this->_result = this->_expression.top();
	this->_expression.pop();
}

void RPN::calculate(int n1, int n2, char op)
{
	switch(op)
	{
		case ('+'):
			this->_expression.push(n1 + n2);
			break;
		case ('-'):
			this->_expression.push(n1 - n2);
			break;
		case ('*'):
			this->_expression.push(n1 * n2);
			break;
		case ('/'):
			if (n2 == 0)
				throw NoDivisionByZeroException();
			this->_expression.push(n1 / n2);
			break;
	}
}

const char* RPN::NoDivisionByZeroException::what() const throw()
{
	return ("Exception: Cant' divide by zero");
}

const char* RPN::TwoOperandsException::what() const throw()
{
	return ("Exception: Need two operands");
}
