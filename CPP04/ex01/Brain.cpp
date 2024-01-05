/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:41:18 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 17:09:40 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << "Brain copied" << std::endl;
}

Brain& Brain::operator=(const Brain&copy)
{
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called" << std::endl;
}

std::string const& Brain::getIdea(int const &n) const
{
	if (n >= 0 && n < 100)
		return (this->_ideas[n]);
	return (this->_ideas[0]);
}

void Brain::setIdea(std::string const &idea, int const &n)
{
	if (n >= 0 && n < 100)
		this->_ideas[n] = idea;
}
