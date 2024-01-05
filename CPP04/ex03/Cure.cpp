/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:24:11 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/10 16:07:36 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Constructor Cure called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy)
{
	
}

Cure& Cure::operator=(const Cure& obj)
{
	this->_type = obj._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor Cure called" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}