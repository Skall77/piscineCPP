/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:44:21 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/28 11:44:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _data;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& obj);

		~Span();

		void	addNumber(int value);
		int		ShortestSpan() const;
		int		LongestSpan() const;
		void	addManyNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	DisplayContainer() const;

		class NoMoreSpaceException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class AtLeastTwoException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif