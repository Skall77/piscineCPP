/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:44:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/28 11:44:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0)
{
	this->_data.reserve(0);
	std::cout << "Defaut Span Constructor called" << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
	this->_data.reserve(N);
	std::cout << "Span Constructor called" << std::endl;
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span& Span::operator=(const Span& obj)
{
	this->_N = obj._N;
	this->_data = obj._data;

	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor" << std::endl;
}

void Span::addNumber(int value)
{
	if (this->_data.size() == this->_N)
		throw Span::NoMoreSpaceException();
	this->_data.push_back(value);
}

int Span::ShortestSpan() const
{
	std::vector<int> tmp;
	int ret;
	std::vector<int>::iterator i;

	tmp = this->_data;

	if(this->_data.size() < 2)
		throw Span::AtLeastTwoException();
	std::sort(tmp.begin(), tmp.end());

	ret = tmp.at(1) - tmp.at(0);
	for (i = tmp.begin(); i != tmp.end(); i++)
	{
		if (abs(*(i + 1) - *i) < ret)
			ret = abs(*(i + 1) - *i);
	}
	return (ret);
}

int Span::LongestSpan() const
{
	std::vector<int> temp = this->_data;

	if(this->_data.size() < 2)
		throw Span::AtLeastTwoException();
	int min = *std::min_element(temp.begin(), temp.end());
	int max = *std::max_element(temp.begin(), temp.end());

	return abs(max - min);
}

void Span::addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

void Span::DisplayContainer() const
{
	std::vector<int> temp = this->_data;
	std::vector<int>::iterator i;

	for (i = temp.begin(); i != temp.end(); i++)
		std::cout << *i << " / ";
	std::cout << std::endl;
}

char const* Span::NoMoreSpaceException::what() const throw()
{
	return ("They are already N elements stored");
}

char const* Span::AtLeastTwoException::what() const throw()
{
	return ("Need at least two number to get a Span");
}
