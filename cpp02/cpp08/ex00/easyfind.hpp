/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:05:49 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/28 11:05:49 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define	EASYFIND_HPP

#include <algorithm>

class EasyfindException : public std::exception{
	public:
		const char *what() const throw()
		{
			return ("Exception: value is not find in container");
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	if (std::find(container.begin(), container.end(), value) == container.end())
	{
		throw EasyfindException();
	}
	return (std::find(container.begin(), container.end(), value));
}

#endif