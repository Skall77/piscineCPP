/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:18 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 16:41:30 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("")
{
	std::cout << "AAnimal Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	this->_type = copy._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor Called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "????" << std::endl;
}

std::string AAnimal::getType() const
{
	return (_type);
}
