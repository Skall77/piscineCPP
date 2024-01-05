/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:18 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/06 17:49:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : _type("")
{
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
	this->_type = copy._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "????" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}