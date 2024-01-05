/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:32:13 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 14:30:59 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat Copied" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	this->_type = copy._type;
	*this->_brain = *copy._brain;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow ! ฅ^._.^ฅ" << std::endl;
}

std::string Cat::getType() const
{
	return (_type);
}

Brain& Cat::getBrain() const
{
	return (*this->_brain);
}

void Cat::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}