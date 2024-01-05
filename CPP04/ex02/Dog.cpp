/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:46 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 14:31:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	this->_brain = new Brain(*copy._brain);
	this->_type = copy._type;
	std::cout << "Dog Copied" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	this->_type = copy._type;
	*this->_brain = *copy._brain;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouf ! υ´• ﻌ •`υ" << std::endl;
}

std::string Dog::getType() const
{
	return (_type);
}

Brain& Dog::getBrain() const
{
	return (*this->_brain);
}

void Dog::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}