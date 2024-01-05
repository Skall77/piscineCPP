/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:55:00 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/27 09:55:00 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, int length, void (*f)(T&))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void square(T &n)
{
	n = n * n;
}

template <typename T>
void print_element(T &elem)
{
	std::cout << elem << std::endl;
}

#endif