/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:04:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main(void) 
{
	srand(time(NULL));
	/*test functions with correct Span */
	Span s(5);
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		s.addNumber((rand() % 2000) - 1000);
	}
	s.DisplayContainer();
	std::cout << "The shortest span is : " << s.ShortestSpan() << std::endl;
	std::cout << "The longest span is : " << s.LongestSpan() << std::endl;
	std::cout << std::endl;

	/*try to add more Number than it can store */
	try
	{
		s.addNumber((rand() % 2000) - 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	/*try to use a Span function with not enough numbers */

	try
	{
		Span sp(1);
		sp.addNumber((rand() % 2000) - 1000);
		sp.ShortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	/* try with a really big span */

	std::vector<int>	vect;
	for (int i = 0; i < 20000; i++)
		vect.push_back((rand() % 2000000) - 1000000);
	
	Span super_span(20000);
	super_span.addManyNumber(vect.begin(), vect.end());

	//super_span.DisplayContainer();
	std::cout << std::endl;
	std::cout << "The shortest span is : " << super_span.ShortestSpan() << std::endl;
	std::cout << "The longest span is : " << super_span.LongestSpan() << std::endl;
	std::cout << std::endl;
	return(0);
}