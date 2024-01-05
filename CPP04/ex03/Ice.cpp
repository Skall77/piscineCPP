/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/10 15:55:01 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructor Ice called" << std::endl;
}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	
}

Ice& Ice::operator=(const Ice& obj)
{
	this->_type = obj._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor Ice called" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
